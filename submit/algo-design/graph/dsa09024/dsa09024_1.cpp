#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<vector<int>>edges;
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
void bfs(Graph *g, int start) {
    vector<bool> visited(g->nV, false);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    vector<int> path;
    path.push_back(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g->edges[u].size(); i++) {
            int x = g->edges[u][i];
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                path.push_back(x);
            }
        }
        
    }
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1 << " ";
    }

}
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
    Graph *g  = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
    }
    bfs(g, start - 1);

}