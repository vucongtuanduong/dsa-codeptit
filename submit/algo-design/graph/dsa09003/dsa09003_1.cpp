#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
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
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u].push_back(v);
    }
    for (int i = 1; i <= nV; i++) {
        cout << i << ": ";
        for (int j = 0; j < g->edges[i].size(); j++) {
            cout << g->edges[i][j] << " ";
        }
        cout << endl;
    }
}