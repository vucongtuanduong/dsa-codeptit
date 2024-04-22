#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
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
        for (auto v : g->edges[u]) {
            if (!visited[v]) {
                cnt++;
                st.push(u);
                st.push(v);
                visited[v] = true;
                break;
            }
        }
    }
    return cnt;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE  = nE;
    g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u,v ;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    vector<bool> visited(g->nV, false);
    for (int i = 0; i < nV; i++) {
        int total = 0;
        visited[i] = true;
        if (i == 0) {
            total = dfs(g, 1, visited);
        } else {
            total = dfs(g, 0, visited);
        }
        if (total != g->nV - 1) {
            cout << i + 1 << " ";
        }
        fill(visited.begin(), visited.end(), false);
        
    }
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
