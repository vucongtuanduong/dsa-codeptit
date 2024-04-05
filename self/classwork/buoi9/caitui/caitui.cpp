#include <bits/stdc++.h>
using namespace std;
int n, v;
vector<pair<int,int>>a;
vector<int> x;
int res, deltak, bk, gk;
void testCase();
void init();
void Try(int i);
bool cmp(pair<int,int>a, pair<int,int> b);
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
bool cmp(pair<int,int>a, pair<int,int> b) {
    double x = (1.0 * a.second )/ (a.first);
    double y = (1.0 * (b.second)) / (b.first);
    return y > x;
}
void Try(int i) {
    for (int j = 1; j >= 0; j--) {
        x[i] = j;
        deltak = deltak + x[i] * a[i].second;
        bk = bk - x[i] * a[i].first;
        if (i == n - 1) {
            if (bk >= 0) {
                res = deltak;
            }
        } else {
            gk = deltak + bk * a[i + 1].second / a[i + 1].first;
            if (gk > res && bk > 0) {
                Try(i + 1);
            }
        }
        deltak = deltak - x[i] * a[i].second;
        bk = bk + x[i] * a[i].first;
    }
}
void init() {
    res = 0;
    cin >> n >> v;
    a.resize(n);
    x.resize(n);
    deltak = 0;
    bk = v;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
}
void testCase() {
    init();
    Try(0);
    cout << res;
}
