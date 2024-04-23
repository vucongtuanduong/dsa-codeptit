#include <bits/stdc++.h>
using namespace std;
struct Graph {
    int nV, nE;
    vector<vector<int>> edges;
};
int dfs(Graph *g, int start, vector<bool> &visited) {
    visited[start] = true;
    stack<int> st;
    st.push(start);
    int cnt = 1;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(u);
                st.push(v);
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
void testCase() {
    int n, m;
    cin >> n >> m;
    Graph *g = new Graph;
    g->nV = n;
    g->nE = m;
    g->edges.resize(g->nV);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    int res = 0;
    vector<bool> visited(g->nV, false);
    for (int i = 0; i < g->nV; i++) {
        int cnt;
        if (!visited[i]) {
            cnt = dfs(g, i, visited);
        }
        res = max(res, cnt);
    }
    cout << res;
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
