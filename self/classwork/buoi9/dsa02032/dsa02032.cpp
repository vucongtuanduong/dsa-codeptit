#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> a;
vector<int>y;
vector<string> kq;
void testCase();
void init();
void result(int i);
void Try(int i, int sum, int cur);

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
void result(int i) {
    string res = "{";
    for (int j = 0; j <= i; j++) {
        res += to_string(y[j]) + " ";
    }
    res.pop_back();
    res += "}";
    kq.push_back(res);
}
void init() {
    kq.clear();
    cin >> n >> x;
    a.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void Try(int i, int sum, int cur) {
    for (int j = cur; j < n; j++) {
        if (sum + a[j] <= x) {
            y[i] = a[j];
            sum += a[j];
            if (sum == x) {
                result(i);
            } else {
                Try(i + 1, sum, j);
            }
            sum -= a[j];
        }
    }
}
void testCase() {
    init();
    Try(0, 0, 0);
    if (kq.size() == 0) {
        cout << "-1";
    } else {
        cout << kq.size() << " ";
        for (auto temp : kq) {
            cout << temp << " ";
        }
    }
}