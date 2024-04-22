#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<int>edges[1001];
};
int dfs(Graph *g, int start) {
    vector<bool>visited(g->nV, false);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    set<int> se;
    se.insert(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto v : g->edges[u]) {
            if (!visited[v]) {
                st.push(u);
                st.push(v);
                visited[v] = true;
                se.insert(v);
                break;
            }
        }
    }
    return se.size();

}
int isStronglyConnected(Graph *g) {
    vector<bool>visited(g->nV, false);
    for (int i = 0; i < g->nV; i++){ 
        if (dfs(g, i) != g->nV) {
            return 0;
        }
        
    }
    return 1;
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
        // g->edges[v - 1].push_back(u - 1);
    }
    if (isStronglyConnected(g)) {
        cout << "YES";
    } else {
        cout << "NO";
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
