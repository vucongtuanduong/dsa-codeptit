#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int nV;
    int nE;
    vector<vector<int>> edges;

    Graph(int nV, int nE) {
        this->nV = nV;
        this->nE = nE;
        this->edges.resize(this->nV);
    }
};
int dfs(Graph *g, int start, vector<bool> &visited) {
    // vector<bool> visited(g->nV, false);
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
void reinit(vector<bool> &visited) {
    for (int i =0 ; i < visited.size(); i++) {
        visited[i] = false;
    }
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph* g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    vector<bool> visited(g->nV, false);
    for (int i = 0; i < nV; i++) {
        visited[i] = true;
        int start = 0;
        if (i == 0) {
            start = 1;
        }
        if (dfs(g, start, visited) != g->nV - 1) {
            cout << i + 1 << " ";
        }
        reinit(visited);

    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}