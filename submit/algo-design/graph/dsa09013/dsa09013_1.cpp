#include <bits/stdc++.h>
using namespace std;

struct Graph{
    int nV;
    int nE;
    vector<vector<bool>> edges;
    vector<pair<int,int>> listEdges;
};

bool dfs(Graph *g, int start);
void listBridge(Graph *g);
void testCase();

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}

bool dfs(Graph *g, int start) {
    vector<bool> visited(g->nV , false);
    visited[start] = true;
    stack<int> st;
    st.push(start);
    vector<int> path;
    path.push_back(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int i = 0; i < g->nV; i++ ) {
            if (g->edges[u][i] == 1 && !visited[i]) {
                st.push(u);
                st.push(i);
                visited[i] = true;
                path.push_back(i);
                break;
            }
        }
    }
    return path.size() == g->nV;
}

void listBridge(Graph *g) {
    for (int i = 0; i < g->listEdges.size(); i++) {
        g->edges[g->listEdges[i].first][g->listEdges[i].second] = 0;
        g->edges[g->listEdges[i].second][g->listEdges[i].first] = 0;
        if (!dfs(g, 0)) {
            cout << g->listEdges[i].first + 1 << " " << g->listEdges[i].second + 1 << " ";
        }
        g->edges[g->listEdges[i].first][g->listEdges[i].second] = 1;
        g->edges[g->listEdges[i].second][g->listEdges[i].first] = 1;
    }
}

void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges = vector<vector<bool>>(nV, vector<bool>(nV, 0));
    for (int i = 0; i < g->nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1][v - 1] = 1;
        g->edges[v - 1][u - 1] = 1;
        g->listEdges.push_back(make_pair(u - 1, v - 1));
    }
    listBridge(g);
}