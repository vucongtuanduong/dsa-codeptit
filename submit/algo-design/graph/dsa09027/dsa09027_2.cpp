#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>> edges;
};
bool bfs(Graph *g,int start, int end) {
    // vector<int> precedence(g->nV, -1);
    vector<bool>visited(g->nV, false);
    queue<int>q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g->edges[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                if (v == end) {
                    return true;
                }
            }
        }
    }
    return false;
    
    
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    int query;
    cin >> query;
    
    while (query--) {
        int start, end;
        cin >> start >> end;
        if (bfs(g,start - 1, end - 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
}
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
