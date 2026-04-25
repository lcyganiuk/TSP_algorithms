#include "tsp.h"
#include <iostream>


void printMatrix(const TSPInstance& inst) {
    std::cout << "Macierz odleglosci dla: " << inst.name << "\n";
    for (int i = 0; i < inst.n; i++) {
        for (int j = 0; j < inst.n; j++)
            std::cout << inst.matrix[i][j] << " ";
        std::cout << "\n";
    }
}