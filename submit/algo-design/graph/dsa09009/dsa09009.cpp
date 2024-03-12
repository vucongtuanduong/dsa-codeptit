#include <iostream>
#include <queue>
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
void bfs(Graph *g, int u, bool *visited) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= g->nV; i++) {
            if (g->edges[x][i] == true && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
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
            bfs(g, i, visited);
            count++;
        }
    }
    return count;
}

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
    cout << countConnectedComponents(g);
    delete g;
}
