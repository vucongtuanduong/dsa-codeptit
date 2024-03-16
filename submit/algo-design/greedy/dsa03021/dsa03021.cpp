#include<bits/stdc++.h>
using namespace std;
void testCase();
bool check(int i, vector<int> a);
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    testCase();

    return 0;
}
bool check(int i, vector<int> a) {
    for (auto x : a) {
        if (x / i == x / (i + 1)) {
            return false;
        }
    }
    return true;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i  < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = a[0]; i >= 1; i--) {
        if (check(i, a)) {
            int res = 0;
            for (auto x : a) {
                res += x / (i + 1) + 1;

            }
            cout << res;
            return;
        }
    }
}