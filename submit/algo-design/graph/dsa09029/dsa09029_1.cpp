#include <bits/stdc++.h>
using namespace std;
int ok = false;
struct Graph{
    int nV, nE;
    vector<int> edges[1001];
};
void dfs(Graph *g, int start, vector<bool> &visited, int cnt) {
    if (cnt == g->nV) {
        ok = true;
    }
    if (ok) {
        return;
    }
    for (int v : g->edges[start]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(g, v, visited, cnt + 1);
            if (ok) {
                return;
            }
            visited[v] = false;
        }
    }
}
int hamilton(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        vector<bool> visited(g->nV, false);
        visited[i] = true;
        dfs(g, i, visited, 1);
        if (ok) {
            return 1;
        }
    }
    return 0;
}
void testCase() {
    ok = false;
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    // g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >>  u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    cout << hamilton(g);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}