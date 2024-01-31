#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    bool edges[1001][1001];
};
void testCase();
void bfs(Graph *g, int v,bool *visited, int *predecessor);
void path(int *predecessor, int src, int dest);
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void path(int *predecessor, int src, int dest) {
    if (predecessor[dest] == -1) {
        cout << -1;
        return;
    } else {
        vector<int> path;
        path.push_back(dest);
        while (src != dest && predecessor[dest] != -1) {
            dest = predecessor[dest];
            path.push_back(dest);

        }
        if (src != dest) {
            cout << -1;
            return;
        } else {
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] + 1 << " ";
            }
    }
    }
}
void testCase() {
    int nV, nE, src, dest;
    cin >> nV >> nE >> src >> dest;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            g->edges[i][j] = false;
        }
    }
    for (int i = 0; i < nE; i++) {
        int v, w;
        cin >> v >> w;
        g->edges[v - 1][w - 1] = true;
        // g->edges[w - 1][v - 1] = true;
    }
    bool *visited = new bool[1001];
    int *predecessor = new int[1001];
    for (int i = 0; i < 1001; i++) {
        visited[i] = false;
        predecessor[i] = -1;
    }
    bfs(g, src - 1, visited, predecessor);
    // for (int i = 0; i < nV; i++) {
    //     cout << predecessor[i] + 1 << " ";
    // }
    // cout << endl;
    path(predecessor, src - 1, dest - 1);
}
void bfs(Graph *g, int v,bool *visited, int *predecessor){
    
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g->nV; i++) {
            if (g->edges[u][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                predecessor[i] = u;
            }
        }
    }
    // for (int i = 0; i < g->nV; i++) {
    //     cout << predecessor[i] + 1 << " ";
    // }
    // cout << endl;
}