#ifndef PARALLEL_ALGORITHMS_H
#define PARALLEL_ALGORITHMS_H

#include <vector>
#include <thread>
#include <algorithm>
#include <numeric>
#include <iterator>

template<typename Iterator, typename Predicate>
size_t parallel_count_if(Iterator first, Iterator last, Predicate pred, size_t K) {
    size_t total_size = std::distance(first, last);
    if (total_size == 0 || K == 0) return 0;

    size_t chunk_size = total_size / K;
    size_t remainder = total_size % K;

    std::vector<std::thread> threads;
    std::vector<size_t> results(K);

    Iterator current = first;

    for (size_t i = 0; i < K; ++i) {
        size_t current_chunk_size = chunk_size + (i < remainder ? 1 : 0);
        Iterator chunk_end = current;
        std::advance(chunk_end, current_chunk_size);

        threads.emplace_back([current, chunk_end, pred, &results, i]() {
            results[i] = std::count_if(current, chunk_end, pred);
            });

        current = chunk_end;
    }

    for (auto& t : threads) {
        t.join();
    }

    return std::accumulate(results.begin(), results.end(), 0ULL);
}

#endif