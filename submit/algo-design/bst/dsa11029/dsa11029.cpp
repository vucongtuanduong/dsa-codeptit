#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int nV;
    vector<vector<int>> edges;

    Graph(int nV) {
        this->nV = nV;
        this->edges.resize(nV);
    }
};

vector<int> leafNodes;
vector<int> pre;

void bfs(Graph *g) {
    int start = 0;
    vector<bool> visited(g->nV, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bool isLeaf = true;
        for (int u : g->edges[current]) {
            if (!visited[u]) {
                visited[u] = true;
                pre[u] = current;
                q.push(u);
                isLeaf = false;
            }
        }
        if (isLeaf) {
            leafNodes.push_back(current);
        }
    }
}

void testCase() {
    int n;
    cin >> n;
    leafNodes.clear();
    pre.clear();
    Graph *g = new Graph(n);
    pre.resize(g->nV, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
    }
    bfs(g);
    sort(leafNodes.begin(), leafNodes.end());
    for (int x : leafNodes) {
        stack<int> st;
        st.push(x);
        while (x != 0) {
            x = pre[x];
            st.push(x);
        }
        while (!st.empty()) {
            cout << st.top() + 1 << " ";
            st.pop();
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}