#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> a, res;
vector<int> b;
vector<bool> used;
void result() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][b[i]];
    }
    vector<int> temp;
    if (sum == k) {
        res.push_back(b);
    }
}
void Try(int i) {
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = true;
            b[i] = j;
            if (i == n - 1) {
                result();
            } else {
                Try(i + 1);
            }
            used[j] = false;
        }
    }
}
void testCase() {
    res.clear();
    cin >> n >> k;
    a.resize(n, vector<int>(n));
    b.resize(n);
    used.resize(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    Try(0);
    cout << res.size() << endl;
    for (auto b : res) {
        for (int i = 0; i < n; i++) {
            cout << b[i] + 1 << " ";
        }
        cout << endl;
    }
}
int main() {
    // Write your code here
    testCase(); 
    return 0;
}
