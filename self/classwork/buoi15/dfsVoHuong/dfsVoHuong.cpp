#include <bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int nV, nE;
        vector<vector<int>> edges;
        Graph(int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
            this->edges.resize(this->nV);
        }
};
void dfsRec(Graph *g, int x, vector<bool> &visited) {
    visited[x] = true;
    cout << x + 1 << " ";
    for (int v : g->edges[x]) {
        if (!visited[v]) {
            dfsRec(g, v, visited);
        }
    }
}
void dfs(Graph *g, int start) {
    stack<int> st;
    vector<bool> visited(g->nV, false);
    vector<int> path;
    st.push(start);
    visited[start] = true;
    path.push_back(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                st.push(u);
                st.push(v);
                visited[v] = true;
                path.push_back(v);
                break;
            }
        }
    }
    for (int u : path) {
        cout << u + 1 << " ";
    }
}
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    vector<bool> visited(g->nV, false);
    dfs(g, start - 1);
    // dfsRec(g, start - 1, visited);

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
