#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
void bfs(Graph *g, int src, int *predecessor);
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
void bfs(Graph *g, int src, int *predecessor) {
    queue<int> q;
    q.push(src);
    predecessor[src] = -1;
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        for (int i = 0; i < g->edges[w].size(); i++ ){
            int x = g->edges[w][i];
            if (predecessor[x] == 0) {
                q.push(x);
                predecessor[x] = w;
            }
        }
    }
}
void testCase(){ 
    Graph *g = new Graph;
    int nV, nE, src, dest;
    cin >> nV >> nE >> src >> dest;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++ ) {
        int u, v;
        cin >> u >> v;
        g->edges[u].push_back(v);
        g->edges[v].push_back(u);
    }
    int predecessor[1001];
    for (int i = 0; i <= nV; i++ ){
        predecessor[i] = 0;
    }
    bfs(g, src, predecessor);
    if (predecessor[dest] == -1) {
        cout << "-1";
    } else {
        stack<int> path;
        int u = dest;
        while (u != src) {
            path.push(u);
            u = predecessor[u];
        }
        path.push(src);
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
    }

    delete g;
}