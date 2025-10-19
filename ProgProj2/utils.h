#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <functional>
#include <chrono>

bool is_even(int x);

std::vector<int> generate_random_data(size_t size);

template<typename Func>
double measure_time(Func func, int iterations = 5) {
    using namespace std::chrono;
    double total_time = 0.0;

    for (int i = 0; i < iterations; ++i) {
        auto start = high_resolution_clock::now();
        func();
        auto end = high_resolution_clock::now();
        total_time += duration<double, std::milli>(end - start).count();
    }

    return total_time / iterations;
}

#endif // UTILS_H