#include "tsp.h"
#include <vector>
#include <limits>
#include <chrono>
#include <iostream>

int nearestNeighbour(const TSPInstance& inst) {
    int n = inst.n;
    std::vector<bool> visited(n, false);
    int cost = 0;
    int current = 0;
    visited[current] = true;

    for (int step = 1; step < n; step++) {
        int next = -1;
        int minCost = std::numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            if (!visited[j] && inst.matrix[current][j] < minCost) {
                minCost = inst.matrix[current][j];
                next = j;
            }
        }
        cost += minCost;
        current = next;
        visited[current] = true;
    }
    cost += inst.matrix[current][0];
    return cost;
}