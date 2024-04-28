#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int, int>  b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void testCase() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int res = 1;
    int value = a[0].second;
    for(int i = 1; i < n; i++) {
        if (a[i].first >= value) {
            res ++;
            value = a[i].second;
        } 
    }
    cout << res;
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
