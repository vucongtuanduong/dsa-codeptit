#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
struct Edge{
    int vertices, weight;
};
struct Graph{
    int nV, nE;
    vector<vector<Edge>> edges;
};
void dijkstra(Graph *g, int start) {
    //priority queue to keep track of the vertices which currently has the minimum path from source
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(g->nV, INF);
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : g->edges[u]) {
            int v = x.vertices;
            int weight = x.weight;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < g->nV; i++) {
        cout << dist[i] << " ";
    }
}
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(nV);
    for (int i = 0; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g->edges[u - 1].push_back({v - 1, w});
        g->edges[v - 1].push_back({u - 1, w});
    }
    dijkstra(g, start - 1);
}
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
