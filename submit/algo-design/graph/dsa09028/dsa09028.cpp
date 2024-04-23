#include<bits/stdc++.h>
using namespace std;

bool isSafe(int v, bool graph[11][11], int color[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[11][11], int m, int color[], int v, int V) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[11][11], int m, int V) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0, V)) {
        return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E, M;
        cin >> V >> E >> M;
        bool graph[11][11];
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u][v] = true;
            graph[v][u] = true;
        }
        if (graphColoring(graph, M, V))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}