#include <iostream>
#include <fstream>

using namespace std;

void dfs(int v, int n, bool* visited, int** matrix) {
    visited[v] = true;
    cout << v << endl;
    for (int i = 0; i < n; i++) {
        if (matrix[v][i] == 1 && !visited[i]) {
            dfs(i, n, visited, matrix);
        }
    }
}

int main() {
    ifstream input("input.txt");
    int n;
    input >> n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            input >> matrix[i][j];
        }
    }
    input.close();

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    dfs(0, n, visited, matrix);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;
    return 0;
}