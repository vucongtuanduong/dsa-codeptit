#include <bits/stdc++.h>
using namespace std;
class Graph {
public:
    int nR;
    int nC;
    vector<vector<int>> edges;

    Graph (int nR, int nC) {
        this->nR = nR;
        this->nC = nC;
        this->edges.resize(nR, vector<int>(nC));
    }
};
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(Graph *g, int i, int j) {
    g->edges[i][j] = 0;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < g->nR && y >= 0 && y < g->nC && g->edges[x][y]) {
            dfs(g, x, y);
        }
    }
}
void testCase() {
    int n, m;
    cin >> n >> m;
    Graph *g = new Graph(n, m);
    for (int i =0; i < n; i++) {
        for (int j = 0;  j  < m; j++) {
            cin >> g->edges[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g->edges[i][j]) {
                cnt++;
                dfs(g, i, j);
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
