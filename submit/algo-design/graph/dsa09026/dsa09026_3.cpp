#include <bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int nV;
        int nE;
        vector<vector<int>> edges;

        Graph (int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
            this->edges.resize(nV);
        }
};
void bfs(Graph *g, int start, int end) {
    queue<int> q;
    vector<bool> visited(g->nV, false);
    stack<int> path;
    vector<int> precedence(g->nV, -1);
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
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
    if (precedence[end] == -1) {
        cout << "-1";
        return;
    }
    while (precedence[end] != -1) {
        path.push(end);
        end = precedence[end];
    }
    if (path.size() == -1) {
        cout << "-1";
        return;
    }
    path.push(start);
    while (!path.empty()) {
        cout << path.top() + 1 << " ";
        path.pop();
    }
}
void testCase() {
    int nV, nE, start, end;
    cin >> nV >> nE >> start >> end;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v-  1);
        // g->edges[v - 1].push_back(u - 1);
    }
    bfs(g, start - 1, end - 1);

}
int main() {
    // Write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
