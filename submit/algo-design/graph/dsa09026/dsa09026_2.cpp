#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>> edges;
};
void bfs(Graph *g, int start, int end) {
    vector<bool>visited(g->nV, false);
    queue<int>q;
    q.push(start);
    visited[start] = true;
    vector<int> precedence(g->nV, -1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g->edges[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                precedence[v] = u;
            }
        }
    }
    if (precedence[end] == -1) {
        cout << "-1";
        return;
    }
    stack<int> path;
    path.push(end);
    while (precedence[end] != -1) {
        path.push(precedence[end]);
        end = precedence[end];
    }
    while (!path.empty()) {
        cout << path.top() + 1 << " ";
        path.pop();
    }

}
void testCase() {
    int nV, nE, start, end;
    cin >> nV >> nE >> start >> end;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
    }
    bfs(g, start - 1, end - 1);
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
