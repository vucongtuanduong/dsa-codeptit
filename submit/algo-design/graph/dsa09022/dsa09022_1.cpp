#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<vector<int>>edges;
};
void testCase();
void dfs(Graph *g, int start);
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
void dfs(Graph *g, int start) {
    vector<bool> visited(g->nV, false);
    visited[start] = true;
    stack<int> st;
    st.push(start);
    vector<int> path;
    path.push_back(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int i = 0; i < g->edges[u].size(); i++) {
            int x = g->edges[u][i];
            if (!visited[x]) {
                st.push(u);
                st.push(x);
                visited[x] = true;
                path.push_back(x);
                break;
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
        // cout << u << "  " << v << endl;
        g->edges[u - 1].push_back(v - 1);
        // g->edges[v - 1].push_back(u - 1);
    }
    dfs(g, start - 1);

}