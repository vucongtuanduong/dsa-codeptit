#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a, b;
bool ok = false;
void testCase();
void Try(int sum, int start);
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
void Try(int sum, int start) {
    if (sum == 0) {
        ok = true;
        cout << "[";
        for (int i = 0; i < b.size(); i++) {
            cout << b[i];
            if (i != b.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    for (int i = start; i < n; i++) {
        if (a[i] <= sum) {
            b.push_back(a[i]);
            Try(sum - a[i], i + 1);
            b.pop_back();
        }
    }
}
void testCase() {
    cin >> n >> k;
    a.resize(n);
    b.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    Try(k, 0);
    if (!ok) {
        cout << "-1";
    }
    ok = false;
}