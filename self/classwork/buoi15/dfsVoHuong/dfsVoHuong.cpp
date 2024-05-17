#include <bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int nV, nE;
        vector<vector<int>> edges;
        Graph(int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
            this->edges.resize(this->nV);
        }
};
void dfsPath(Graph *g, int start, int end) {
    vector<int> precedence(g->nV, -1);
    vector<bool> visited(g->nV, false);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(u);
                st.push(v);
                precedence[v] = u;
                break;
            }
        }
    }
    int temp = end;
    stack<int> path;
    path.push(temp);
    while(precedence[temp] != -1) {
        temp = precedence[temp];
        path.push(temp);
    }
    if (path.size() == 0) {
        cout << "-1";
        return;
    }
    while (!path.empty()) {
        cout << path.top() + 1 <<" ";
        path.pop();
    }
}
void dfsSpanningTree(Graph *g, int start) {
    vector<pair<int, int>> spanningTree;
    stack<int> st;
    vector<bool> visited(g->nV, false);
    st.push(start);
    visited[start] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(u);
                st.push(v);
                spanningTree.push_back({u, v});
                
                break;
            }
        }
    } 
    if (spanningTree.size() != g->nV - 1) {
        cout << "Khong co cay khung!";
        return;
    }
    for (auto x : spanningTree) {
        cout << x.first + 1 << " " << x.second + 1 << endl;
    }
}
void bfs(Graph *g, int start) {
    queue<int> q;
    vector<bool> visited(g->nV, false);
    q.push(start);

    visited[start] = true;
    cout << start + 1 << " ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                q.push(v);
                cout << v + 1 << " ";
                visited[v] = true;
            }
        }
    }
}
void dfsRec(Graph *g, int x, vector<bool> &visited) {
    visited[x] = true;
    cout << x + 1 << " ";
    for (int v : g->edges[x]) {
        if (!visited[v]) {
            dfsRec(g, v, visited);
        }
    }
}
void dfs(Graph *g, int start) {
    stack<int> st;
    vector<bool> visited(g->nV, false);
    vector<int> path;
    st.push(start);
    visited[start] = true;
    path.push_back(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g->edges[u]) {
            if (!visited[v]) {
                st.push(u);
                st.push(v);
                visited[v] = true;
                path.push_back(v);
                break;
            }
        }
    }
    for (int u : path) {
        cout << u + 1 << " ";
    }
}

void testCase2(){ 
    int nV, nE, start, end;
    cin >> nV >> nE >> start >> end;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    // dfsPath(g, start - 1, end - 1);
    dfsSpanningTree(g, start - 1);
}
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    vector<bool> visited(g->nV, false);
    // dfs(g, start - 1);
    // dfsRec(g, start - 1, visited);
    bfs(g, start - 1);

}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}
