#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    int edges[1001][1001];

};
void testCase();
void dfs(Graph *g, int v,bool *visited);
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;   
}
void dfs(Graph *g, int v,bool *visited) {
    visited[v] = true;
    for (int i = 0; i < g->nV; i++) {
        if (g->edges[v][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
    // for (int i = 0; i < g->nV; i++) {
    //     cout << visited[i] << " ";
    // }
    // cout << endl;
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    memset(g->edges, 0 ,sizeof(g->edges));
    for (int i = 0; i < nE; i++) {
        int v, w;
        cin >> v >> w;
        g->edges[v - 1][w - 1] = 1;
        g->edges[w - 1][v - 1] = 1;
    }
    int numConnectedComponents = 0;
    bool *visited = new bool[1001];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < nV; i++) {
        if (!visited[i]) {
            dfs(g, i, visited);
            numConnectedComponents++;
            
        }
    }
    // for (int i = 0; i < nV; i++) {
    //     g->edges[i].clear();
    // }
    cout << numConnectedComponents;
    delete g;
}