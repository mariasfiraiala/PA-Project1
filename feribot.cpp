#include <bits/stdc++.h>

bool comparator(uint_fast64_t mid,
                uint_fast32_t n,
                uint_fast32_t k,
                std::vector <uint_fast64_t> weights) {
    uint_fast32_t partitions = 1;
    uint_fast64_t partitions_sum = 0;

    for (uint_fast32_t i = 0; i < n; ++i) {
        if (weights[i] > mid)
            return false;

        partitions_sum += weights[i];
        if (partitions_sum > mid) {
            ++partitions;
            partitions_sum = weights[i];
        }
    }

    if (partitions <= k)
        return true;

    return false;
}

uint_fast64_t task(uint_fast32_t n,
                   uint_fast32_t k,
                   std::vector <uint_fast64_t> weights) {
    auto it = max_element(std::begin(weights), std::end(weights));

    uint_fast64_t left = *it;
    uint_fast64_t right = std::accumulate(weights.begin(), weights.end(), 0ULL);

    uint_fast64_t ans = 0;
    while (left <= right) {
        uint_fast64_t mid = left + (right - left) / 2;

        if (comparator(mid, n, k, weights)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main(void) {
    freopen("feribot.in", "r", stdin);
    freopen("feribot.out", "w", stdout);

    uint_fast32_t n, k;
    std::cin >> n >> k;

    std::vector <uint_fast64_t> weights;
    uint_fast64_t weight;
    for (uint_fast32_t i = 0; i < n; ++i) {
        std::cin >> weight;
        weights.push_back(weight);
    }

    std::cout << task(n, k, weights);
    return 0;
}
