#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<vector<int>> edges;
};
void testCase();
bool isTree(Graph *g, int u, int parent, vector<bool> &visited);
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
bool isTree(Graph *g, int u, int parent, vector<bool> &visited) {
    visited[u] = true;
    for (int v : g->edges[u]) {
        if (!visited[v]) {
            if (!isTree(g, v, u, visited)) {
                // cout << v << ", " << u << ", " << "isTree(g, v, u, visited) : false\n"; 
                return false;
            }
        } else if (v != parent) {
            return false;
        }
    }
    return true;
}
void testCase() {
    int nV;
    cin >> nV;
    int nE = nV - 1;
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
    vector<bool>visited(g->nV, false);
    if (isTree(g, 0, -1, visited) && count(visited.begin(), visited.end(), true) == g->nV) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}