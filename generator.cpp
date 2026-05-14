#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <filesystem>

using namespace std;

random_device rd;
mt19937 gen(rd());

int randomWeight(int minW = 1, int maxW = 100) {
    uniform_int_distribution<> dist(minW, maxW);
    return dist(gen);
}

vector<vector<int>> generateSymmetric(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = randomWeight();
            matrix[i][j] = w;
            matrix[j][i] = w;
        }
    }

    return matrix;
}

vector<vector<int>> generateAsymmetric(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matrix[i][j] = randomWeight();
            }
        }
    }

    return matrix;
}

void saveToFile(const string& filename, const vector<vector<int>>& matrix) {
    ofstream file(filename);
    int n = matrix.size();

    file << n << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file << matrix[i][j] << " ";
        }
        file << "\n";
    }

    file.close();
}

int main() {
    filesystem::create_directories("data/sym");
    filesystem::create_directories("data/asym");

    int instanceCount = 10;
    int minSize = 6;
    int maxSize = 15;

    for (int i = 0; i < instanceCount; i++) {
        int n = minSize + (i % (maxSize - minSize + 1));

        auto matrix = generateSymmetric(n);

        string filename = "data/sym/sym_" + to_string(n) + ".txt";
        saveToFile(filename, matrix);
    }

    for (int i = 0; i < instanceCount; i++) {
        int n = minSize + (i % (maxSize - minSize + 1));

        auto matrix = generateAsymmetric(n);

        string filename = "data/asym/asym_" + to_string(n) + ".txt";
        saveToFile(filename, matrix);
    }

    cout << "Instancje wygenerowane." << endl;

    return 0;
}
