#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int nV;
    vector<vector<int>> edges;

    Graph(int nV) {
        this->nV = nV;
        this->edges.resize(nV);
    }
};

int bfs(Graph *g) {
    int start = 0;
    vector<int> len(g->nV, 0);
    vector<bool> visited(g->nV, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int res = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int u : g->edges[current]) {
            if (!visited[u]) {
                visited[u] = true;
                len[u] = len[current] + 1;
                res = max(res, len[u]);
                q.push(u);
            }
        }
    }
    return res;
}

void testCase() {
    int n;
    cin >> n;
    Graph *g = new Graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
    }
    cout << bfs(g);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}