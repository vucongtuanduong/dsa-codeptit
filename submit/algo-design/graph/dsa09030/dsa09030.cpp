#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> adj[], int v, vector<int>& color) {
    for (int u : adj[v]) {
        if (color[u] == -1) {
            color[u] = 1 - color[v];
            if (!isBipartite(adj, u, color))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> adj[N+1];
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(N+1, -1);
        bool flag = true;
        for (int i = 1; i <= N; i++) {
            if (color[i] == -1) {
                color[i] = 1;
                if (!isBipartite(adj, i, color)) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}