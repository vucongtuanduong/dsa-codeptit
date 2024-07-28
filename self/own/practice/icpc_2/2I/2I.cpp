#include <bits/stdc++.h>
using namespace std;
class Graph {
    public int nV, nE;
    vector<vector<int>> edges;

    public Graph (int nV, int nE) {
        this.nV = nV;
        this.nE = nE;
        this.edges.resize(nV);
    }

};
int dfs(Graph *g, int start) {
    int res = 0;
    vector<bool> visited(g->nV, false);
}
int main() {
    // Write your code here
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    int q = nV;
    set<int> se;
    for (int i = 0; i < nV; i++) {
        int x;
        cin >> x;
        q--;
        se.insert(x - 1);
        int cnt = 0;
        if (used == 0) {
            cnt = dfs(g,nV - 1);
        } else {
            cnt = dfs(g, 0);
        }
        if (cnt != q) {
            cout << "NO";
        } else {
            cout << "YES";
        }
    }

    return 0;
}
