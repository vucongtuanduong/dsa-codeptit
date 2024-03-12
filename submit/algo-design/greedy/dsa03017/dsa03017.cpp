#include <bits/stdc++.h>
using namespace std;
void testCase();
bool cmp(pair<long long,char> a, pair<long long, char> b);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
bool cmp(pair<long long,char> a, pair<long long, char> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
void testCase() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    map<char,long long> mp;
    for (long long i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    priority_queue<long long> pq;
    for (auto x : mp) {
        pq.push(x.second);
    }
    while (n > 0) {
        if (pq.empty()) {
            break;
        }
        long long x = pq.top();
        pq.pop();
        x--;
        pq.push(x);
        n--;
    }
    long long ans = 0;
    while (!pq.empty()) {
        long long x = pq.top();
        pq.pop();
        ans += x * x;
    }
    cout << ans;
}