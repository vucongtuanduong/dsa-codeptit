#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 10;
int a[MAX][MAX];
vector<string> res;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const string myMove = "URDL";
void testCase();
void Try(int i, int j, string s);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void Try(int i, int j, string s) {
    if (i == n && j == n) {
        res.push_back(s);
        return;
    }
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] == 1) {
            a[x][y] = 0;
            Try(x, y, s + myMove[k]);
            a[x][y] = 1;
        }
    }
}
void testCase() {
    res.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == 0 || a[n][n] == 0) {
        cout << -1;
        return;
    }
    a[1][1] = 0;
    Try(1, 1, "");
    if (res.size() == 0) {
        cout << "-1";
        return;
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}