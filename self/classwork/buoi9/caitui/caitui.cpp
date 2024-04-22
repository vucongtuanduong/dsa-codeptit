#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, v;
vector<pair<int, int>> a;
vector<int> x;
int res, deltak, bk, gk;
void testCase();
void init();
void Try(int i);
bool cmp(const pair<int, int> &a, const pair<int, int> &b);
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    double x = static_cast<double>(a.second) / a.first;
    double y = static_cast<double>(b.second) / b.first;
    return y < x;
}
void Try(int i) {
    for (int j = 1; j >= 0; j--) {
        x[i] = j;
        deltak = deltak + x[i] * a[i].second;
        bk = bk - x[i] * a[i].first;
        if (bk < 0) {
            bk += x[i] * a[i].first;
            deltak -= x[i] * a[i].second;
            continue;
        }
        if (i == n - 1) {
            res = max(res, deltak);
        } else {
            gk = deltak + static_cast<double>(bk * a[i + 1].second) / a[i + 1].first;
            if (gk > res) {
                Try(i + 1);
            }
        }
        deltak -= x[i] * a[i].second;
        bk += x[i] * a[i].first;
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
    cout << res << endl;
}
