#include <iostream>
#include <vector>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
int countConnectedComponents(Graph *g, int notCount, bool *visited);
void listPendant(Graph *g);
void dfs(Graph *g, int v, bool *visited, int notCount);
void reinit(Graph *g, bool *visited);
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
void reinit(Graph *g, bool *visited) {
    for (int i = 0; i <= g->nV; i++ ) {
        visited[i] = false;
    }
}
void dfs(Graph *g, int v, bool *visited, int notCount) {
    visited[v] = true;
    for (int i = 0; i < g->edges[v].size(); i++ ){ 
        int w = g->edges[v][i];
        if (!visited[w] && w != notCount) {
            dfs(g, w, visited, notCount);
        }
    }
}
int countConnectedComponents(Graph *g, int notCount, bool *visited) {
    int count  = 0;
    for (int w = 1; w <= g->nV; w++) {
        if (!visited[w] && w != notCount) {
            count++;
            dfs(g, w, visited, notCount);
        }
    }
    return count;
}

void listPendant(Graph *g) {
    bool visited[1001];
    reinit(g, visited);
    int countFull = countConnectedComponents(g, -1, visited);
    for (int i = 1; i <= g->nV; i++) {
        reinit(g, visited);
        int countCheck = countConnectedComponents(g, i, visited);
        if (countCheck > countFull) {
            cout << i << " ";
        }
    }
}
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++ ) {
        int v, u;
        cin >> v >> u;
        g->edges[v].push_back(u);
        g->edges[u].push_back(v);
    }
    listPendant(g);

    delete g;

}