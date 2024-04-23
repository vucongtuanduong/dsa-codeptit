#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<vector<int>> edges;
};
vector<int> res;
void testCase();
void dfs(Graph *g, int u, int parent, vector<int> path, vector<bool> &visited);
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
void dfs(Graph *g, int u, int parent, vector<int> path, vector<bool> &visited) {
    visited[u]  = true;
    for (int v : g->edges[u]) {
        if (v == 0 && v != parent && res.empty()) {
            path.push_back(v);
            res = path;
            return;
        }
        if (!visited[v]) {
            path.push_back(v);
            dfs(g, v, u, path, visited);
            path.pop_back();
        }
    }
}
void testCase() {
    res.clear();
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(g->nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    for (auto &i: g->edges) {
        sort(i.begin(), i.end());
    }
    vector<bool> visited(g->nV, false);
    dfs(g, 0, -1, {0}, visited);
    if (res.empty()) {
        cout << "NO";
    } else {
        for (int i : res) {
            cout << i + 1 << " ";
        }
    }
}