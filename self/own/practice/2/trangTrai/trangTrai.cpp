#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int,int>b ) {
    return a.second > b.second;
}

void testCase() {
    int n;
    cin >> n;
    pair<int,int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, cmp);
    vector<bool> taken(1e9 + 1, false);
    int res = 0;
    for (auto x : a) {
        while(taken[x.first] && x.first) {
            x.first--;
        }
        if (!taken[x.first] && x.first) {
            res += x.second;
            taken[x.first] = true;
        }
    }
    cout << res;
}
int main() {
    // Write your code 
    testCase();
    return 0;
}
