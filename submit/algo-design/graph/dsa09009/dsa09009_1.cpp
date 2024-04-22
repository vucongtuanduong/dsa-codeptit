#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<int>edges[1001];
};
void dfs(Graph *g, int start, vector<bool>&visited) {
    
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto v : g->edges[u]) {
            if (!visited[v]) {
                st.push(u);
                st.push(v);
                visited[v] = true;
                break;
            }
        }
    }
}
int numConnectedCom(Graph *g) {
    int cnt = 0;
    vector<bool>visited(g->nV, false);
    for (int i = 0; i < g->nV; i++){ 
        if (!visited[i]) {
            dfs(g, i, visited);
            cnt++;
        }
        
    }
    return cnt;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE ;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    // g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    cout << numConnectedCom(g);
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
