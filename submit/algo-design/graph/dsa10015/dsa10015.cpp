#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
    int u, v, w;
};
struct Graph{
    int nV;
    int nE;
    vector<Edge>edges;
};
class DisjointSet{
    private:
        vector<int>parent, rank;
    public:
        DisjointSet(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for (int i = 0; i <= n; i++) {
                parent[i]  = i;
            }
        }
        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void unionSets(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                if (rank[rootX] == rank[rootY]) {
                    rank[rootX]++;
                }
            }
        }
};
bool cmp(Edge a, Edge b);
vector<Edge> kruskalMST(Graph *g);
void testCase();
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
vector<Edge> kruskalMST(Graph *g) {
    sort(g->edges.begin(), g->edges.end(), cmp);
    DisjointSet dsu(g->nV);
    vector<Edge>mst;
    for (Edge  edge : g->edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (dsu.find(u) != dsu.find(v)) {
            mst.push_back({u, v, w});
            dsu.unionSets(u, v);
        }
    }
    return mst;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i =0 ; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g->edges.push_back({u, v, w});
    }
    vector<Edge>mst = kruskalMST(g);
    int mstCost = 0;
    for (Edge  edge : mst) {
        mstCost += edge.w;
    }
    cout << mstCost;
}
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
