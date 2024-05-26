#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
vector<int> res;
void Try(int i) {
    if (res.size() == k) {
        for (auto x : res) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        for (int j = i; j < n; j++) {
            res.push_back(a[j]);
            Try(j + 1);
            res.pop_back();
        }
    }
}
void testCase() {
    cin >> n >> k;
    a.resize(n);
    res.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    Try(0);
}
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
