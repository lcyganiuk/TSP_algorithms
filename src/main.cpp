#include "config.h"
#include "loader.h"
#include <iostream>
#include <chrono>
#include <string>

int nearestNeighbour(const TSPInstance&);
int repetitiveNearestNeighbour(const TSPInstance&);
int randomTSP(const TSPInstance&);
int bruteForce(const TSPInstance&);

int main() {
    Config cfg = loadConfig("config.txt");

    // RAND
    {
        TSPInstance inst = loadInstance("data/" + cfg.randFile);
        auto start = std::chrono::high_resolution_clock::now();
        int cost = randomTSP(inst);
        auto end = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        double err = (static_cast<double>(cost - cfg.optRand) / cfg.optRand) * 100.0;
        std::cout << "[RAND] " << inst.name
                  << " | Koszt: " << cost
                  << " | Blad: " << err << "% "
                  << "| Czas: " << ms << " ms\n";
    }

    // NN
    {
        TSPInstance inst = loadInstance("data/" + cfg.nnFile);
        auto start = std::chrono::high_resolution_clock::now();
        int cost = nearestNeighbour(inst);
        auto end = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        double err = (static_cast<double>(cost - cfg.optNN) / cfg.optNN) * 100.0;
        std::cout << "[NN] " << inst.name
                  << " | Koszt: " << cost
                  << " | Blad: " << err << "% "
                  << "| Czas: " << ms << " ms\n";
    }

    // RNN
    {
        TSPInstance inst = loadInstance("data/" + cfg.rnnFile);
        auto start = std::chrono::high_resolution_clock::now();
        int cost = repetitiveNearestNeighbour(inst);
        auto end = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - start).count();
        double err = (static_cast<double>(cost - cfg.optRNN) / cfg.optRNN) * 100.0;
        std::cout << "[RNN] " << inst.name
                  << " | Koszt: " << cost
                  << " | Blad: " << err << "% "
                  << "| Czas: " << ms << " ms\n";
    }

    // Brute Force
    {
        if (cfg.bfFiles == "all") {
            for (int n = 6; n <= 15; n++) {
                for (const std::string& type : {"sym", "asym"}) {
                    std::string filename = "data/" + type + "_" + std::to_string(n) + ".txt";
                    TSPInstance inst = loadInstance(filename);
                    auto start = std::chrono::high_resolution_clock::now();
                    int cost = bruteForce(inst);
                    auto end = std::chrono::high_resolution_clock::now();
                    double ms = std::chrono::duration<double, std::milli>(end - start).count();
                    std::cout << "[BF] " << type << "_" << n
                              << " | Koszt: " << cost
                              << " | Czas: " << ms << " ms\n";
                }
            }
        } else {
            int n = std::stoi(cfg.bfFiles);
            for (const std::string& type : {"sym", "asym"}) {
                std::string filename = "data/" + type + "_" + std::to_string(n) + ".txt";
                TSPInstance inst = loadInstance(filename);
                auto start = std::chrono::high_resolution_clock::now();
                int cost = bruteForce(inst);
                auto end = std::chrono::high_resolution_clock::now();
                double ms = std::chrono::duration<double, std::milli>(end - start).count();
                std::cout << "[BF] " << type << "_" << n
                          << " | Koszt: " << cost
                          << " | Czas: " << ms << " ms\n";
            }
        }
    }

    return 0;
}