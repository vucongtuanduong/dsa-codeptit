#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> a;
vector<int> x;
void testCase();
void Try(int i);
void solve();
int main() {
    // Write your code here
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    testCase();
    return 0;
}
void solve() {
    int count = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 0) {
            count++;
            
        }
    }
    if (count == k) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == 0) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == x.size() - 1) {
            solve();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    a.clear();

    cin >> n >> k;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for (auto x : mp) {
        a.push_back(x.first);
    }
    x.resize(a.size());
    Try(0);
}