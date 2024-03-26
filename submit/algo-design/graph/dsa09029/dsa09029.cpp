#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int>edges[1001];
};
bool ok;
void testCase();
void dfs(Graph *g, int start, vector<bool> &visited);
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
void dfs(Graph *g, int start, vector<bool> &visited, int count) {
    if (count == g->nV) {
        ok = true;
    }
    if (ok){
        return;
    }
    for (int v : g->edges[start]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(g, v, visited, count + 1);
            if (ok) return;  // Add this line
            visited[v] = false;
        }
    }
}
void testCase() {
    ok = false;
    int nV , nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < g->nV; i++) {
        vector<bool> visited(g->nV, false);
        visited[i] = true;
        dfs(g, i, visited, 1);
        if (ok) {
            cout << "1";
            return;
        }
    }
    cout << "0";
}
