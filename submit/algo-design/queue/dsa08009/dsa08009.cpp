#include<bits/stdc++.h>
using namespace std;

int minOperations(int S, int T) {
    queue<int> q;
    unordered_map<int, int> dist;
    q.push(T);
    dist[T] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == S) {
            return dist[cur];
        }
        if (cur % 2 == 0 && dist.find(cur / 2) == dist.end()) {
            q.push(cur / 2);
            dist[cur / 2] = dist[cur] + 1;
        }
        if (cur < S && dist.find(cur + 1) == dist.end()) {
            q.push(cur + 1);
            dist[cur + 1] = dist[cur] + 1;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int S, T;
        cin >> S >> T;
        cout << minOperations(S, T) << endl;
    }
    return 0;
}