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
        this->edges.resize(nV);
    }
};

vector<int> bfs(Graph* g, int start) {
    queue<int> q;
    vector<bool> visited(g->nV, false);
    vector<int> precedence(g->nV, -1);
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                visited[v] = true;
                precedence[v] = u;
                q.push(v);
            }
        }
    }
    return precedence;
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
    int q;
    cin >> q;
    while (q--) {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        vector<int> precedence = bfs(g, start);
        if (precedence[end] == -1) {
            cout << "NO\n";
        } else {
            int cnt = 0;
            while (precedence[end] != -1) {
                cnt++;
                end = precedence[end];
            }
            if (cnt != 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}