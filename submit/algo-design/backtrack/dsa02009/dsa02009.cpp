#include <bits/stdc++.h>
using namespace std;
void testCase();
void Try(int count, vector<int> &a, int sum, bool &check, int x, int k);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void Try(int count, vector<int> &a, int sum, bool &check, int x, int k) {
    if (check) {
        return;
    }
    if (count == k) {
        check = true;
        return;
    }
    if (x > sum) {
        return;
    }
    if (x == sum) {
        Try(count + 1, a, sum, check, 0, k);
    }
    for (int i = 0; i < a.size(); i++) {
        Try(count, a, sum, check, x + a[i], k);
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool check = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % k == 0) {
        sum /= k;
        Try(0, a, sum, check, 0, k);
        if (check) {
            cout << "1";
            return;
        } else {
            cout << "0";
            return;
        }
    } else {
        cout << "0";
        return;
    }

}