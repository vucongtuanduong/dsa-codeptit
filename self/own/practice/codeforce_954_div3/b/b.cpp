#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool stabilizeCell(vector<vector<int>>& matrix, int i, int j, int n, int m) {
    int value = matrix[i][j];
    bool isStable = true;

    if (i > 0 && matrix[i - 1][j] >= value) isStable = false;
    if (i < n - 1 && matrix[i + 1][j] >= value) isStable = false;
    if (j > 0 && matrix[i][j - 1] >= value) isStable = false;
    if (j < m - 1 && matrix[i][j + 1] >= value) isStable = false;

    if (isStable) {
        matrix[i][j]--;
        return true;
    }
    return false;
}

void stabilizeMatrix(vector<vector<int>>& matrix, int n, int m) {
    bool changed;
    do {
        changed = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (stabilizeCell(matrix, i, j, n, m)) {
                    changed = true;
                }
            }
        }
    } while (changed);
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