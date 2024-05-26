#include <bits/stdc++.h>
using namespace std;
class  Graph {
    public:
        int nV, nE;
        vector<vector<int>> edges;
        Graph (int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
            this->edges.resize(nV);
        }
};
void dfs(Graph *g, int start = 0) {
    vector<bool> visited(g->nV, false);
    vector<int>precedence(g->nV, -1);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                st.push(u);
                st.push(v);
                visited[v] = true;
                precedence[v] = u;
                break;
            }
        }
    }
    

    for (int i = 1; i < g->nV; i++) {
        if (precedence[i] == -1) {
            cout << "-1\n";
        } else {
            vector<int> path;
            int x = i;
            while (precedence[x] != -1) {
                path.push_back(x);
                x = precedence[x];
            }
            path.push_back(0);
            reverse(path.begin(), path.end());
            for (auto c : path) {
                cout << c + 1 << " ";
            }
            cout << endl;
        }
        vector<bool> visited1(g->nV, false);
        vector<int>precedence1(g->nV, -1);
        queue<int> q;
        q.push(i);
        visited1[i] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g->edges[u]) {
                if (!visited1[v]) {
                    visited1[v] = true;
                    precedence1[v] = u;
                    q.push(v);
                }
            }
        }
        if (precedence1[start] == -1) {
            cout << "-1\n";
        } else {
            vector<int> path;
            int x = start;
            while (precedence1[x] != -1) {
                path.push_back(x);
                x = precedence1[x];
            }
            path.push_back(i);
            reverse(path.begin(), path.end());
            for (auto c : path) {
                cout << c + 1 << " ";
            }
            cout << endl;
        }
    }
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    dfs(g);
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
