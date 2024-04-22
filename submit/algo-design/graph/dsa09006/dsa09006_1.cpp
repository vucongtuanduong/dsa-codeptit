#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>> edges;
};
void dfs(Graph *g, int start, int end) {
    vector<bool>visited(g->nV, false);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    vector<int> precedence(g->nV, -1);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto v : g->edges[u]) {
            if (!visited[v]) {
                st.push(u);
                st.push(v);
                visited[v] = true;
                precedence[v] = u;
                break;
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
    g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    dfs(g, start - 1, end - 1);
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
