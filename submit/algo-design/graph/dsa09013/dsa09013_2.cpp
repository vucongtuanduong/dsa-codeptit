#include <bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int nV;
        int nE;
        vector<vector<int>> edges;//adjacency matrix

        Graph (int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
            this->edges.resize(nV, vector<int>(nV, 0));
        }
};
int dfs(Graph *g) {
    int cnt = 1;
    stack<int> st;
    vector<bool> visited(g->nV, false);
    st.push(0);
    visited[0] = true;
    while (!st.empty()) {

        int u = st.top();
        st.pop();
        for (int i = 0; i < g->nV; i++) {
            if (g->edges[u][i] == 1 && !visited[i]) {
                st.push(u);
                st.push(i);
                // cout << "i: " << i << endl;
                visited[i] = true;
                cnt++;
                break;
            }
        }
    }
    // cout << "cnt: " << cnt << endl;
    return cnt;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph(nV, nE);
    vector<pair<int, int>> a;
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back({u - 1, v - 1});
        g->edges[u - 1][v - 1] = 1;
        g->edges[v - 1][u - 1] = 1;
    }
    for (int i = 0; i < nE; i++) {
        int u = a[i].first;
        int v = a[i].second;
        g->edges[u][v] = 0;
        g->edges[v][u] = 0;
        if (dfs(g) != g->nV) {
            cout << u + 1 << " " << v + 1 << " ";
        }
        g->edges[u][v] = 1;
        g->edges[v][u] = 1;
    }

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
