#include <bits/stdc++.h>
using namespace std;
void testCase();
bool cmp(pair<int,int>a, pair<int, int> b);
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
void testCase() {
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int res = 1;
    int time = a[0].second;
    for (int i = 1; i < n; i++ ){
        if (a[i].first >= time) {
            time = a[i].second;
            res++;
        }
    }
    cout << res;

}
bool cmp(pair<int,int>a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}