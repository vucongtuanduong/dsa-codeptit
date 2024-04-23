#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void dijkstra(vector<pair<int, int>> adj[], int V, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i)
        cout << dist[i] << " ";
    cout << "\n";
}

void solve() {
    int V, E, src;
    cin >> V >> E >> src;
    src--; // 0-indexed
    vector<pair<int, int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // 0-indexed
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // Remove this line if the graph is directed
    }

    dijkstra(adj, V, src);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}