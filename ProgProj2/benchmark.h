#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <functional>

void run_experiments();

double benchmark_sequential(const std::vector<int>& data,
    std::function<bool(int)> predicate,
    size_t& result);

void benchmark_policies(const std::vector<int>& data,
    std::function<bool(int)> predicate);

void benchmark_custom_parallel(const std::vector<int>& data,
    std::function<bool(int)> predicate,
    double baseline_time);

#endif