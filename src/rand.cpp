#include "tsp.h"
#include <vector>
#include <algorithm>
#include <random>
#include <limits>

int randomTSP(const TSPInstance& inst) {
    int n = inst.n;
    std::vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(perm.begin(), perm.end(), g);

    int cost = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        cost += inst.matrix[perm[i]][perm[next]];
    }
    return cost;
}