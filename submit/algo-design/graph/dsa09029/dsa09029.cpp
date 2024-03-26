#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<vector<int>> edges;
};
void testCase();
void dfs(Graph *g, int start, vector<bool> &visited);
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
void dfs(Graph *g, int start, vector<bool> &visited) {
    visited[start] = true;
    stack<int> st;
    st.push(start);
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                st.push(u);
                st.push(v);
                visited[v] = true;
            } 
        }
    }
}
void testCase() {
    int nV;
    cin >> nV;
    int nE = nV - 1;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(g->nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < g->nV; i++) {
        vector<bool> visited(g->nV, false);
        dfs(g, i, visited);
        if (count(visited.begin(), visited.end(), true) != g->nV) {
            cout << "1";
            return;
        }
    }
    cout << "0";
}