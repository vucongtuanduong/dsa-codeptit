#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void adjustCell(vector<vector<int>>& matrix, int i, int j, int n, int m) {
    int maxNeighbor = 0;
    if (i > 0) maxNeighbor = max(maxNeighbor, matrix[i-1][j]);
    if (i < n-1) maxNeighbor = max(maxNeighbor, matrix[i+1][j]);
    if (j > 0) maxNeighbor = max(maxNeighbor, matrix[i][j-1]);
    if (j < m-1) maxNeighbor = max(maxNeighbor, matrix[i][j+1]);
    matrix[i][j] = min(matrix[i][j], maxNeighbor);
}

bool needsAdjustment(const vector<vector<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int maxNeighbor = 0;
            if (i > 0) maxNeighbor = max(maxNeighbor, matrix[i-1][j]);
            if (i < n-1) maxNeighbor = max(maxNeighbor, matrix[i+1][j]);
            if (j > 0) maxNeighbor = max(maxNeighbor, matrix[i][j-1]);
            if (j < m-1) maxNeighbor = max(maxNeighbor, matrix[i][j+1]);
            if (matrix[i][j] > maxNeighbor) return true;
        }
    }
    return false;
}

void stabilizeMatrix(vector<vector<int>>& matrix, int n, int m) {
    while (needsAdjustment(matrix, n, m)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                adjustCell(matrix, i, j, n, m);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        stabilizeMatrix(matrix, n, m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}