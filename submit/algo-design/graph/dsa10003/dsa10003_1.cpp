#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<pair<int, int>>edges;
};
class DisjointSet {
    private:
        vector<int>parent;
    public:
        DisjointSet(int n) {
            parent.resize(n + 1, -1);
        }
        int find(int x) {
            if (parent[x] == -1) {
                return x;
            }
            return parent[x] = find(parent[x]);
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
    for (auto &edge : g->edges) {
        int u = edge.first;
        int v = edge.second;
        if (dsu.find(u) == dsu.find(v)) {
            return true;
        }
        dsu.unionSets(u, v);
    }
    return false;
}
void testCase() {
    int nV , nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges.push_back(make_pair(u - 1, v- 1));
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
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}