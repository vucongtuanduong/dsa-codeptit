#include <iostream>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
void dfs(Graph *g, int v, bool *visited);
bool hasPath();
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
void dfs(Graph *g, int v, bool *visited) {

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
        g->edges[v].push_back(u);
    }
}