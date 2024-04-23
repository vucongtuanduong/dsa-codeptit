#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> dinhduong;
vector<int> cnt;
vector<int> edge[200005];
void bfs(int s) {
    for (auto x : edge[s]) {
        bfs(x);
        dinhduong[s] += dinhduong[x];
        cnt[s] += cnt[x] + 1;
    }
    dinhduong[s] += cnt[s];
}
void testCase() {
    
    cin >> n;
    dinhduong.resize(n, 0);
    cnt.resize(n, 0);
    for (int i = 0; i < n; i++) {
        dinhduong[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        int nut;
        cin >> nut;
        edge[nut - 1].push_back(i);
    }
    bfs(0);
    for (int i = 0; i < n; i++) {
        cout << dinhduong[i] << " ";
    }
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
