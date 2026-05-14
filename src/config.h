#pragma once
#include <string>

struct Config {
    std::string randFile;
    int optRand;

    std::string nnFile;
    int optNN;

    std::string rnnFile;
    int optRNN;

    std::string bfFiles;
};

Config loadConfig(const std::string& filename);
