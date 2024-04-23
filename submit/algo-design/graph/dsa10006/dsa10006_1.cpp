#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>> edges;
};
vector<pair<int, int>> dfs(Graph *g, int start) {
    vector<pair<int, int>> res;
    vector<bool> visited(g->nV, false);
    visited[start] = true;
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(u);
                st.push(v);
                res.push_back({u, v});
                break;
            }
        }
    }
    return res;
}
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
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
    vector<pair<int, int>> res = dfs(g, start - 1);
    if (res.size() != g->nV - 1) {
        cout << "-1\n";
        return;
    }
    for (auto x : res) {
        cout << x.first + 1 << " " << x.second + 1 << endl;
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