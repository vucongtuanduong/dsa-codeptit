#include<bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool visited[105];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        memset(visited, false, sizeof(visited));
        dfs(x);
        vector<bool> reachable_from_x(visited, visited + n + 1);
        memset(visited, false, sizeof(visited));
        dfs(y);
        vector<bool> reachable_from_y(visited, visited + n + 1);
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (reachable_from_x[i] && reachable_from_y[i]) {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}