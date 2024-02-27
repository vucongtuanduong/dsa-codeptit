#include <iostream>
using namespace std;
struct Graph{
    int nV;
    int nE;
    int edges[1001][1001];
};
void testCase();
int countConnectedComponents(Graph *g);
void dfs(Graph *g, int u, bool *visited);
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
void dfs(Graph *g, int u, bool *visited) {
    visited[u] = true;
    for (int v = 1; v <= g->nV; v++) {
        if (g->edges[u][v] == 1 && !visited[v]) {
            dfs(g, v, visited);
        }
    }
}
int countConnectedComponents(Graph *g) {
    bool visited[1001];
    for (int i = 1; i <= g->nV; i++) {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 1; i <= g->nV; i++) {
        if (!visited[i]) {
            dfs(g, i, visited);
            count++;
        }
    }
    return count;
}
void listBridges(Graph *g) ;
void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 1; i <= nV; i++) {
        for (int j = 1; j <= nV; j++) {
            g->edges[i][j] = 0;
        }
    }
    for (int i = 0; i < nE; i++) {
        int u, v;
        cin >> u >> v;
        g->edges[u][v] = 1;
        g->edges[v][u] = 1;
    }
    listBridges(g);
}
void listBridges(Graph *g)  {
    // Write your code here
    int count = countConnectedComponents(g);
    for (int i = 1; i <= g->nV; i++) {
        for (int j = i + 1; j <= g->nV; j++) {
            if (g->edges[i][j] == 1) {
                g->edges[i][j] = 0;
                g->edges[j][i] = 0;
                int newCount = countConnectedComponents(g);
                if (newCount > count ) {
                    cout << i << " " << j << " ";  
                }
                g->edges[i][j] = 1;
                g->edges[j][i] = 1;
            }
        }
    }
}