#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>> edges;
};
int bfs(Graph *g) {
    int cnt = 1;
    vector<bool> visited(g->nV, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                visited[v]  = true;
                q.push(v);
                cnt++;
            }
        }
    }
    return cnt;
}
bool isTree(Graph *g) {
    if (bfs(g) != g->nV) {
        return false;
    } else {
        return true;
    }
}
void testCase() {
    int nV;
    cin >> nV;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nV - 1;
    g->edges.resize(nV);
    for (int i = 0; i < nV - 1; i++) {
        int u, v;
        cin >>  u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    if (isTree(g)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
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
