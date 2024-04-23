#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV, nE;
    vector<vector<int>>edges;
};
bool check(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        for (int v : g->edges[i]) {
            if (g->edges[v].size() != g->edges[i].size()) {
                return false;
            }
        }

    }
    return true;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE ;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(100001);
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u - 1].push_back(v - 1);
        g->edges[v - 1].push_back(u - 1);
    }
    if (check(g)) {
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