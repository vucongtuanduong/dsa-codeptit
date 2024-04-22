#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> a(105, vector<int>(105));
int res;
void testCase();
void Try(int i, int j);
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void Try(int i, int j) {
    if (i == n - 1 && j == m - 1) {
        res++;
        return;
    }
    if (i + 1 < n) {
        Try(i + 1, j);
    } 
    if (j + 1 < m) {
        Try(i, j + 1);
    }
}
void testCase() {
    cin >> n >> m;
    res = 0;
    // a.resize(n, vector<int>(m)); // Resize using m for columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    Try(0, 0);
    cout << res;
}
