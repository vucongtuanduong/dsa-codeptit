#include <bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int nV, nE;
        vector<pair<int,int> > edges;
        Graph(int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
            // this->edges.resize(nV);
        }
};
class DisjointSet {
    public:
        vector<int> parent;
        DisjointSet(int n) {
            parent.resize(n + 1, -1);
        }

        int find(int x) {
            if (parent[x] == -1) {
                return x;
            }
            return (parent[x] = find(parent[x]));
        }

        void unionSets(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
            }
        }
};
bool hasCycle(Graph *g) {
    DisjointSet dsu(g->nV);
    for (auto x : g->edges) {
        int u = x.first;
        int v = x.second;
        if (dsu.find(u) == dsu.find(v)) {
            return true;
        }
        dsu.unionSets(u, v);
    }
    return false;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges.push_back({u - 1, v - 1});
    }
    if (hasCycle(g)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
