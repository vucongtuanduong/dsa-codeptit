#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1,1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1,0,  1};
struct Graph{
    int numRows;
    int numCols;
    vector<vector<int>>edges;
};
void dfs(Graph *g, int i, int j) {
    g->edges[i][j] = 0;
    for (int k = 0; k < 8; k++) {
        int new_x = i + dx[k];
        int new_y = j + dy[k];
        if (new_x >= 0 && new_x < g->numRows && new_y >= 0 && new_y < g->numCols && g->edges[new_x][new_y] == 1)  {
            dfs(g, new_x, new_y);
        }
    }
}
void testCase() {
    int n, m;
    cin >> n >> m;
    Graph *g = new Graph;
    g->numRows = n;
    g->numCols = m;
    g->edges.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g->edges[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j  = 0; j < m; j++) {
            if (g->edges[i][j] == 1) {
                dfs(g, i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}