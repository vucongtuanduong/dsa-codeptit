#include <bits/stdc++.h>
using namespace std;
int n, v;
vector<pair<int,int>>a;
vector<int> x;
int res, deltak, bk, gk;
void testCase();
void init();
void Try(int i);
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
void Try(int i) {
    for (int j = 1; j >= 0; j--) {
        x[i] = j;
        deltak = deltak + x[i] * a[i].second;
        bk = bk - x[i] * a[i].first;
        if (i == n - 1) {
            if (bk >= 0) {
                res = 
            }
        }
    }
}
void init() {
    res = 0;
    cin >> n >> v;
    a.resize(n);
    x.resize(n);
    deltak = 0;
    bk = b;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
}
void testCase() {
    init();
    Try(0);
}
