#include <bits/stdc++.h>
using namespace std;
int n, k, res;
bool visited[10];
int x[10];
string a[10], b[10];
void testCase();
void Try(int i);
void solve();
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    testCase();

    return 0;
}
void solve() {
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < k; j++) {
            b[i][j] = a[i][x[j]];
        }   
    }
    // for (int i = 0; i < n; i++) {
    //     cout << b[i] << " ";
    // }
    sort(b, b + n);
    int minn = stoi(b[0]);
    int maxx = stoi(b[n - 1]);
    res = min(res, maxx - minn);
}
void Try(int i) {
    for (int j = 0; j < k; j++) {
        if (!visited[j]) {
            x[i] = j;
            visited[j] = true;
            if (i == k - 1) {
                solve();
            } else {
                Try(i + 1);
            }
            visited[j] = false;
        }
    }
}
void testCase() {
    cin >> n >> k;
    res = INT_MAX;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    Try(0);
    cout << res;
}