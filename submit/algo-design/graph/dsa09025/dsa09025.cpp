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
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        
        for (int i = 0; i < g->edges[v].size(); i++) {
            int w = g->edges[v][i];
            if (predecessor[w] == -1) {
                predecessor[w] = v;
                st.push(v);
                st.push(w);
                break;
            }
    }
}
}
void testCase() {
    int nV, nE, src, dest;
    cin >> nV >> nE >> src >> dest;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 1; i <= nV; i++) {
        g->edges[i].clear();
    }
    for (int i = 1; i <= nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u].push_back(v);
    }
    int predecessor[1001];
    for (int i = 0; i <= nV; i++) {
        predecessor[i] = -1;
    }
    dfs(g, src, predecessor);
    if (predecessor[dest] == -1) {
        cout << -1;
    } else {
        vector<int> path;
        int u = dest;
        while (u != src) {
            path.push_back(u);
            u = predecessor[u];
        }
        path.push_back(src);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }
    delete g;
}