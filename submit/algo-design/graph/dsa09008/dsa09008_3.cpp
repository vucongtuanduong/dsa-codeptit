#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int nV;
    int nE;
    vector<vector<int>> edges;

    Graph(int nV, int nE) {
        this->nV = nV;
        this->nE = nE;
        this->edges.resize(1001);
    }
};
void bfs(Graph *g, int start, vector<bool> &visited) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph* g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    int cnt = 0;
    vector<bool> visited(nV, false);
    for (int i = 0; i < nV; i++) {
        if (!visited[i]) {
            if (i == 0) {
                bfs(g, 1, visited);
            } else {
                bfs(g, i, visited);
            }
            
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}