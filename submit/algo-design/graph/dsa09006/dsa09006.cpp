#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
void dfs(Graph *g, int u, int *predecessor);
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
void dfs(Graph *g, int u, int *predecessor) {
    stack<int> st;
    st.push(u);
    predecessor[u] = -1;
    while (!st.empty()) {
        int v = st.top();
        // cout << v << " ";
        st.pop();
        // cout << "Cac dinh ke " << v << ": ";
        // for (int i = 0; i < g->edges[v].size(); i++) {
        //     cout << g->edges[v][i] << " ";
        // }
        // cout << endl;
        for (int i = 0; i < g->edges[v].size(); i++) {
            int w = g->edges[v][i];
            if (predecessor[w] == 0) {
                predecessor[w] = v;
                st.push(v); // push v back onto the stack
                st.push(w); // push the new vertex onto the stack
                break;
            }
        }
    }
}
void testCase() {
    int nV, nE, src, dest;
    cin >> nV >> nE >> src >> dest;
    // cout << nV << " " << nE << " " << src << " " << dest << endl;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 1; i <= nV; i++) {
        g->edges[i].clear();
    }
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        // cout << u << " " << v << endl;
        g->edges[u].push_back(v);
        // for (auto x : g->edges[u]) {
        //     cout << x << " ";
        // }
        // cout << endl;

        g->edges[v].push_back(u);
        // for (auto x : g->edges[v]) {
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    int predecessor[1001];
    for (int i = 0; i <= nV; i++) {
        predecessor[i] = 0;
    }
    dfs(g, src, predecessor);
    if (predecessor[dest] == 0) {
        cout << -1;
    } else {
        stack<int> path;
        int u = dest;
        while (u != src) {
            path.push(u);
            u = predecessor[u];
        }
        path.push(src);
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
    }
    delete g;
}