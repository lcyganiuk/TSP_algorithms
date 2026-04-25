#include "config.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Config loadConfig(const string& filename) {
    Config cfg;
    ifstream fin(filename);

    if (!fin) {
        cerr << "Nie mozna otworzyc config.txt\n";
        exit(1);
    }

    string line;

    // RAND
    getline(fin, line);
    {
        stringstream ss(line);
        ss >> cfg.randFile >> cfg.optRand;
    }

    // NN
    getline(fin, line);
    {
        stringstream ss(line);
        ss >> cfg.nnFile >> cfg.optNN;
    }

    // RNN
    getline(fin, line);
    {
        stringstream ss(line);
        ss >> cfg.rnnFile >> cfg.optRNN;
    }

    // BF
    getline(fin, cfg.bfFiles);

    return cfg;
}