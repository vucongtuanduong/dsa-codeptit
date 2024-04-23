#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>> edges;
};
bool dfsHasCycle(Graph *g, int v, vector<bool> &visited, vector<bool> &onStack) {
    visited[v] = true;
    onStack[v] = true;
    for (int w : g->edges[v]) {
        if (onStack[w]) {
            return true;
        } else if (visited[w] == false) {
            if (dfsHasCycle(g, w, visited, onStack)) {
                return true;
            }
        }
    }
    onStack[v] = false;
    return false;
}
bool hasCycle(Graph *g) {
    vector<bool> visited(g->nV, false);
    vector<bool> onStack(g->nV, false);
    for (int i = 0; i < g->nV; i++) {
        if (!visited[i]) {
            if (dfsHasCycle(g, i, visited, onStack)) {
                return true;
            }
        }
    }
    return false;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(nV);
    for (int i = 0;i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        // g->edges[v - 1].push_back(u - 1);
        
    }
    if (hasCycle(g)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
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
