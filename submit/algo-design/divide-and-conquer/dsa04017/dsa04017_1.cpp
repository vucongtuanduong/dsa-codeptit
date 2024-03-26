#include <bits/stdc++.h>
using namespace std;
void  testCase();
void readArray(vector<long long> &a);
int findDiff(vector<long long> a, vector<long long> b, int l, int r);
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
int findDiff(vector<long long> a, vector<long long> b, int l, int r) {
    if (l >= r) {
        return l + 1;
    }
    int m = (l + r) / 2;
    if (a[m] == b[m]) {
        return findDiff(a, b, m + 1, r);
    } else {
        return findDiff(a, b, l, m);
    }
}
void readArray(vector<long long> &a) {
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}
void  testCase() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n - 1);
    readArray(a);
    readArray(b);
    cout << findDiff(a, b, 0, n -1);
}