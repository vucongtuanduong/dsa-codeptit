#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int nV;
    int nE;
    vector<vector<int>> edges;
};

void dfs(const unique_ptr<Graph>& g, int start, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        for (auto v : g->edges[x]) {
            if (!visited[v]) {
                st.push(x);
                st.push(v);
                visited[v] = true;
                break;
            }
        }
    }
}

int countConnectedComponents(const unique_ptr<Graph>& g) {
    vector<bool> visited(g->nV, false);
    int count = 0;
    for (int i = 0; i < g->nV; i++) {
        if (!visited[i]) {
            dfs(g, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nV, nE;
    cin >> nV >> nE;
    auto g = make_unique<Graph>();
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u].push_back(v);
        g->edges[v].push_back(u);
    }
    int numComponents = countConnectedComponents(g);
    if (nE < nV - 1) {
        cout << "-1";
    } else {
        cout << numComponents - 1;
    }
    return 0;
}