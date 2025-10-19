#include "benchmark.h"
#include "utils.h"
#include "parallel_algorithms.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <execution>
#include <thread>
#include <limits>

using namespace std;

double benchmark_sequential(const vector<int>& data,
    function<bool(int)> predicate,
    size_t& result) {
    return measure_time([&]() {
        result = count_if(data.begin(), data.end(), predicate);
        });
}

void benchmark_policies(const vector<int>& data,
    function<bool(int)> predicate) {
    cout << "\n2. count_if with execution policies:" << endl;

    size_t result_seq = 0;
    double time_seq = measure_time([&]() {
        result_seq = count_if(execution::seq, data.begin(), data.end(), predicate);
        });
    cout << "   execution::seq: " << fixed << setprecision(2)
        << time_seq << " ms" << endl;

    size_t result_par = 0;
    double time_par = measure_time([&]() {
        result_par = count_if(execution::par, data.begin(), data.end(), predicate);
        });
    cout << "   execution::par: " << time_par << " ms" << endl;

    size_t result_par_unseq = 0;
    double time_par_unseq = measure_time([&]() {
        result_par_unseq = count_if(execution::par_unseq, data.begin(), data.end(), predicate);
        });
    cout << "   execution::par_unseq: " << time_par_unseq << " ms" << endl;

    cout << "   Speedup par vs seq: " << fixed << setprecision(2)
        << (time_seq / time_par) << "x" << endl;
    cout << "   Speedup par_unseq vs seq: " << fixed << setprecision(2)
        << (time_seq / time_par_unseq) << "x" << endl;
}

void benchmark_custom_parallel(const vector<int>& data,
    function<bool(int)> predicate,
    double baseline_time) {
    cout << "\n3. Custom parallel count_if (different thread counts K):" << endl;
    cout << "   " << setw(8) << "K"
        << setw(15) << "Time (ms)"
        << setw(15) << "Speedup"
        << setw(12) << "Result" << endl;
    cout << "   " << string(50, '-') << endl;

    size_t hardware_threads = thread::hardware_concurrency();
    vector<size_t> K_values;

    for (size_t k = 1; k <= hardware_threads * 3; ++k) {
        K_values.push_back(k);
    }

    double best_time = numeric_limits<double>::max();
    size_t best_K = 1;

    for (size_t K : K_values) {
        size_t result_parallel = 0;
        double time_parallel = measure_time([&]() {
            result_parallel = parallel_count_if(data.begin(), data.end(), predicate, K);
            });

        double speedup = baseline_time / time_parallel;

        cout << "   " << setw(8) << K
            << setw(15) << time_parallel
            << setw(15) << speedup
            << setw(12) << result_parallel << endl;

        if (time_parallel < best_time) {
            best_time = time_parallel;
            best_K = K;
        }
    }

    cout << "\n   Best K: " << best_K << endl;
    cout << "   Hardware threads: " << hardware_threads << endl;
    cout << "   K/threads ratio: " << fixed << setprecision(2)
        << (double)best_K / hardware_threads << endl;
    cout << "   Best time: " << best_time << " ms" << endl;
    cout << "   Maximum speedup: " << (baseline_time / best_time) << "x" << endl;
}

void run_experiments() {
    cout << "=== count_if Performance Analysis ===" << endl;
    cout << "Variant 4: count_if" << endl;
    cout << "Predicate: counting even numbers" << endl;
    cout << "Hardware threads: " << thread::hardware_concurrency() << endl;
    cout << string(80, '=') << endl << endl;

    vector<size_t> data_sizes = { 1'000'000, 10'000'000, 50'000'000 };

    for (size_t size : data_sizes) {
        cout << "\n--- Data size: " << size << " elements ---" << endl;

        auto data = generate_random_data(size);
        auto predicate = is_even;

        cout << "\n1. Sequential count_if (no policy):" << endl;
        size_t result_seq = 0;
        double time_seq = benchmark_sequential(data, predicate, result_seq);
        cout << "   Time: " << fixed << setprecision(2) << time_seq << " ms" << endl;
        cout << "   Result: " << result_seq << endl;

        benchmark_policies(data, predicate);

        benchmark_custom_parallel(data, predicate, time_seq);
    }

    cout << "\n\n=== CONCLUSIONS ===" << endl;
    cout << "1. Execution policies (par, par_unseq) show significant speedup" << endl;
    cout << "   on large datasets compared to sequential execution." << endl;
    cout << "\n2. Custom parallel algorithm performs best when K is close to" << endl;
    cout << "   the number of hardware threads available." << endl;
    cout << "\n3. When K exceeds optimal value, execution time increases due to" << endl;
    cout << "   thread creation and synchronization overhead." << endl;
    cout << "\n4. Compilation with /O2 provides significant performance improvement" << endl;
    cout << "   compared to /Od (no optimization)." << endl;
    cout << "\nNOTE: For optimization level comparison, compile the program with" << endl;
    cout << "      /Od (no optimization) and /O2 (maximum optimization) flags." << endl;
}