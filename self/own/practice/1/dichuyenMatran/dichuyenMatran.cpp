#include <bits/stdc++.h>
using namespace std;
int n, res;
vector<vector<int>>a;
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};
void testCase();
void Try(int i, int j);
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
void Try(int i, int j) {
    
}
void testCase() {
    res = 0;
    cin >> n;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    Try(0,0);
}