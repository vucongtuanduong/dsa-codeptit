#include <bits/stdc++.h>
using namespace std;
void testCase();
bool cmp(pair<int, int> a, pair<int, int> b);
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
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void testCase() {
    int n;
    cin >> n;
    pair<int,int> job[n];
    for (int i = 0; i < n; i++) {
        cin >> job[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> job[i].second;
    }
    sort(job, job + n, cmp);
    int res = 1;
    int k = job[0].second;
    for (int i = 1; i < n; i++) {
        if (job[i].first >= k) {
            res ++;
            k =job[i].second;
        }
    }
    cout << res;
}