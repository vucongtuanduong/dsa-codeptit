#include <bits/stdc++.h>
using namespace std;
void testCase();
void Try(int i, int j, int &count, int n, int m, bool visited[][105]);
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
void Try(int i, int j, int &count, int n, int m, bool visited[][105]) {
    if (i == n - 1 && j == m - 1) {
        count++;
        return;
    }
    if (i + 1 <= n - 1 && !visited[i + 1][j]) {
        Try(i + 1, j, count, n, m, visited);
    }
    if (j + 1 <= m - 1 && !visited[i][j + 1]) {
        Try(i, j + 1, count, n, m, visited);
    }
}
void testCase() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    bool visited[105][105];
    int count = 0;
    memset(visited, false, sizeof(visited));
    Try(0, 0, count, n, m, visited);
    cout << count;
}