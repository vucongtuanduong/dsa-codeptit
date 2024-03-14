#include <bits/stdc++.h>
using namespace std;
void testCase();
bool cmp(pair<int, int> a, pair<int, int> b);
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
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
void testCase() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int maxLength = 1;
    int last = a[0].second;
    for (int i = 1; i < n; i++) {
        if (a[i].first > last) {
            last = a[i].second;
            maxLength++;
        }
    }
    cout << maxLength;
}