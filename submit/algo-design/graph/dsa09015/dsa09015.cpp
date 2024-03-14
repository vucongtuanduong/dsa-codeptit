#include <bits/stdc++.h>
using namespace std;
struct Graph
{   
    int nV;
    int nE;
    vector<int> edges[1001];
};
void testCase();
bool hasCycle(Graph *g);
bool findCycle(Graph *g, int u, bool *visited, bool *recStack);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
bool findCycle(Graph *g, int u, bool *visited, bool *recStack) {
    if (visited[u] == false) {
        visited[u] = true;
        recStack[u] = true;
        for (int i =0; i < g->edges[u].size(); i++) {
            int current = g->edges[u][i];
            if (!visited[current] && findCycle(g, current, visited, recStack)) {
                return true;
            } else if (recStack[current]) {
                return true;
            }
        }
    }
    recStack[u] = false;
    return false;
}
bool hasCycle(Graph *g) {
    bool *visited = new bool[g->nV];
    bool *recStack = new bool[g->nV];
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < g->nV; i++) {
        if (findCycle(g, i, visited, recStack)) {
            return true;
        }
    }
    return false;
}
void testCase() {
    int nV, nE;
    cin >> nV >>  nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < g->nE; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g->edges[u].push_back(v);
    }
    if (hasCycle(g)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}