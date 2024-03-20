#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
void bfs(Graph *g, int start);
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
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    bfs(g, start - 1);

}
void bfs(Graph *g, int start) {
    queue<int> q;
    bool visited[g->nV];
    vector<int> path;
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
    q.push(start);
    visited[start] = true;
    path.push_back(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < g->edges[u].size(); i++) {
            int x= g->edges[u][i];
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                path.push_back(x);
            }
        }
    }
    for (int i = 0;i < path.size(); i++) {
        cout << path[i] + 1 << " ";
    }
}