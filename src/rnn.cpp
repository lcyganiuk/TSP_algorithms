#include "tsp.h"
#include <vector>
#include <limits>

int repetitiveNearestNeighbour(const TSPInstance& inst) {
    int n = inst.n;
    int bestCost = std::numeric_limits<int>::max();

    for (int start = 0; start < n; start++) {
        std::vector<bool> visited(n, false);
        int cost = 0;
        int current = start;
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
        cost += inst.matrix[current][start];
        if (cost < bestCost) bestCost = cost;
    }
    return bestCost;
}