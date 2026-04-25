#include "loader.h"
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

TSPInstance loadInstance(const string& filename) {
    ifstream file(filename);
    TSPInstance inst;
    inst.name = filename;

    string line;
    int n = 0;

    vector<pair<int,int>> coords;

    while (getline(file, line)) {
        if (line.find("DIMENSION") != string::npos) {
            string tmp;
            stringstream ss(line);
            ss >> tmp >> tmp >> n;
        }

        if (line.find("NODE_COORD_SECTION") != string::npos) {
            break;
        }
    }

    // TSPLIB
    if (n > 0) {
        coords.resize(n);

        for (int i = 0; i < n; i++) {
            int id, x, y;
            file >> id >> x >> y;
            coords[id - 1] = {x, y};
        }

        inst.n = n;
        inst.matrix.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double dx = coords[i].first - coords[j].first;
                double dy = coords[i].second - coords[j].second;
                inst.matrix[i][j] = (int)round(sqrt(dx*dx + dy*dy));
            }
        }

        return inst;
    }

    file.clear();
    file.seekg(0);

    file >> inst.n;
    inst.matrix.resize(inst.n, vector<int>(inst.n));

    for (int i = 0; i < inst.n; i++) {
        for (int j = 0; j < inst.n; j++) {
            file >> inst.matrix[i][j];
        }
    }

    return inst;
}