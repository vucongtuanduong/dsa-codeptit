#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<vector<int>> edges;
};
void testCase();
void bfs(Graph *g, int start, vector<pair<int,int>> &spanningTree);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void bfs(Graph *g, int start, vector<pair<int,int>> &spanningTree) {
    vector<bool> visited(g->nV, false);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                spanningTree.push_back(make_pair(u, v));
            }
        }
    }
}
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
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
    vector<pair<int, int>> spanningTree;
    bfs(g, start - 1, spanningTree);
    if (spanningTree.size() != g->nV - 1) {
        cout << "-1\n";
    } else {
        for (auto x : spanningTree) {
            cout << x.first + 1 << " " << x.second + 1 << endl;
        }
    }
}
