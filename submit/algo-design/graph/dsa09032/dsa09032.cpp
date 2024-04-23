#include<bits/stdc++.h>
using namespace std;

vector<int> parent, rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        rank[a] += rank[b];
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    parent.resize(N+1);
    rank.resize(N+1, 0);
    for (int i = 1; i <= N; i++) {
        make_set(i);
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }
    int max_friends = 0;
    for (int i = 1; i <= N; i++) {
        max_friends = max(max_friends, rank[find_set(i)]);
    }
    cout << max_friends << "\n";
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