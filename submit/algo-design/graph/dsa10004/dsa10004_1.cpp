#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>> edges;
};
int dfs(Graph *g) {
    vector<bool>visited(g->nV, false);
    stack<int> st;
    st.push(0);
    visited[0] = true;
    set<int> se;
    se.insert(0);
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
int deg(Graph *g, int u) {
    int cnt = 0;
    for (auto v : g->edges[u]) {
        cnt++;
    }
    return cnt;
}
int euler(Graph *g) {
    if (g->nV != dfs(g)) {
        return 0;
    }
    int numOdd = 0;
    for (int i = 0; i < g->nV; i++) {
        if (deg(g, i) % 2 == 1) {
            numOdd++;
        }
    }
    if (numOdd == 2) {
        return 1;
    } else if (numOdd == 0){
        return 2;
    } else {
        return 0;
    }

}
void testCase() {
    int nV, nE;
    cin >> nV >> nE ;
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
    cout << euler(g);
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
