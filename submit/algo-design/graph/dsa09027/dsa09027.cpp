#include <bits/stdc++.h>
using namespace std;
//not accepted
struct Graph{
    int nV;
    int nE;
    int edges[1001][1001];
};

void testCase();
void bfs(Graph *g, int v,int *visited, int *predecessor);
bool path(int *predecessor, int src, int dest);

int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}

void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            g->edges[i][j] = 0;
        }
    }
    for (int i = 0; i < nE; i++) {
        int v, w;
        cin >> v >> w;
        g->edges[v][w] = 1;
        g->edges[w][v] = 1;
    }
    int *visited = new int[1001];
    int *predecessor = new int[1001];
    memset(visited, 0, sizeof(int) * 1001);
    memset(predecessor, 0, sizeof(int) * 1001);
    int q;
    cin >> q;
    while (q--) {
        int src, dest;
        cin >> src >> dest;
        bfs(g, src, visited, predecessor);
        if (predecessor[dest] == 0) {
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << endl;
        memset(visited, 0, sizeof(int) * 1001);
        memset(predecessor, 0, sizeof(int) * 1001);
    }
    delete[] visited;
    delete[] predecessor;
    delete g;
}

void bfs(Graph *g, int v,int *visited, int *predecessor){
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int k = 0; k < g->nV; k++) {
            if (!visited[k] && g->edges[x][k] == 1) {
                q.push(k);
                visited[k] = 1;
                predecessor[k] = x;
            }
        }
    }
}