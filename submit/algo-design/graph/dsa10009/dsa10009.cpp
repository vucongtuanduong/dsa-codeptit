#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    edges.resize(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        edges[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u - 1][v - 1] = w;
        edges[v - 1][u - 1] = w;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (edges[i][k] < INT_MAX && edges[k][j] < INT_MAX) // Avoid overflow
                    edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << edges[u - 1][v - 1] << endl;
        
    }
}
int main() {
    // Write your code here
    testCase();
    return 0;
}