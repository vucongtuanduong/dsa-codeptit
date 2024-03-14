#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> adj[], int v, bool visited[], int parent) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); ++i) {
        int neighbour = adj[v][i];
        if (!visited[neighbour]) {
           if (isCyclicUtil(adj, neighbour, visited, v))
              return true;
        }
        else if (neighbour != parent)
           return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int u = 0; u < V; u++) {
        if (!visited[u])
          if (isCyclicUtil(adj, u, visited, -1))
             return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        if (isCyclic(adj, V))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}