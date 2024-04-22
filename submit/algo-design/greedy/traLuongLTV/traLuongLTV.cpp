#include <bits/stdc++.h>
//https://github.com/Cutiepie4/DSAA_PTIT/blob/main/TR%E1%BA%A2%20L%C6%AF%C6%A0NG%20CHO%20L%E1%BA%ACP%20TR%C3%8CNH%20VI%C3%8AN.cpp
using namespace std;
bool cmp(pair<long long , long long > a, pair<long long, long long> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
    // Write your code here
    long long n, x, y, z, res = 0;
    cin >> n >> x >> y >> z;
    vector<pair<long long, long long>> a(n +  1);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for (long long i = n; i > 1; i--) {
        int cnt = 0;
        for (long long j = i - 1; j > 0; j--) {
            if (a[i].first > a[j].second) {
                cnt++;
            }
        }
        res = max(res, (i - cnt) * y + cnt * z + (n - i) * x);
    }
    cout << res;
    return 0;
}
