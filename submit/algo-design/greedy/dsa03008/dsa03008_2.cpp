#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void testCase() {
    int n;
    cin >> n;
    pair<int,int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a, a + n, cmp);
    int cnt = 1;
    int maxEnd = a[0].second;
    for (int i=  1;i  < n; i++) {
        if (a[i].first >= maxEnd) {
            maxEnd= a[i].second;
            cnt++;
        }
    }
    cout << cnt;
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
