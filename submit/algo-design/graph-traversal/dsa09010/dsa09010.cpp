#include <iostream>
#include <vector>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
void dfs(Graph *g, int v, bool *visited);
bool isStronglyConnected(Graph *g);
int countVertices(Graph *g, bool *visited);
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
void dfs(Graph *g, int v, bool *visited) {
    visited[v] = true;
    for (int i = 0; i < g->edges[v].size(); i++) {
        int w = g->edges[v][i];
        if (!visited[w]) {
            dfs(g, w, visited);
        }
    }
}
void reinit(Graph *g, bool *visited) {
    for (int i = 1; i <= g->nV; i++) {
        visited[i] = true;
    }
}
int countVertices(Graph *g, bool *visited) {
    int count = 0;
    for (int i = 1; i <= g->nV; i++) {
        if (visited[i] == true) {
            count++;
        }
    }
    return count;
}
bool isStronglyConnected(Graph *g) {
    bool visited[1001];
    for (int i = 1; i <= g->nV; i++ ) {
        reinit(g, visited);
        dfs(g, i, visited);
        int count = countVertices(g, visited);
        if (count != g->nV) {
            return false;
        }
        
    }
    return true;
}
void testCase() {
    Graph *g = new Graph;
    int nV, nE;
    cin >> nV >> nE;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++ ) {
        int v, u;
        cin >> v >> u;
        g->edges[v].push_back(u);
    }
    if (isStronglyConnected(g)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    delete g;
}