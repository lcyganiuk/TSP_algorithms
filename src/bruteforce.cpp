#include "tsp.h"
#include <vector>
#include <algorithm>
#include <limits>

int bruteForce(const TSPInstance& inst) {
    int n = inst.n;
    std::vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    int bestCost = std::numeric_limits<int>::max();
    do {
        int cost = 0;
        for (int i = 0; i < n; i++)
            cost += inst.matrix[perm[i]][perm[(i+1)%n]];
        if (cost < bestCost) bestCost = cost;
    } while (std::next_permutation(perm.begin()+1, perm.end())); // fix first node

    return bestCost;
}