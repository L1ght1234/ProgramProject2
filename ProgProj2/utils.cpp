#include "utils.h"
#include <random>

bool is_even(int x) {
    return x % 2 == 0;
}

std::vector<int> generate_random_data(size_t size) {
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    for (auto& val : data) {
        val = dis(gen);
    }

    return data;
}