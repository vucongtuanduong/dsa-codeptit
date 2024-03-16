#include <bits/stdc++.h>
using namespace std;
string s[100];
int n;
bool visited[100] = {false};
int f[20][20];
int x[100];
int res = INT_MAX;
void testCase();
void Try(int i);
void check();
int count(string a, string b);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    testCase();
    return 0;
}
int count(string a, string b) {
    map<char,int> mp;
    for (auto i : a) {
        mp[i]++;
    }
    for (auto i : b) {
        mp[i]++;
    }
    int dem = 0;
    for (auto x : mp) {
        dem += (x.second > 1);
    }
    return dem;
}
void check() {
    int count  = 0;
    for (int i = 1; i <= n; i++) {
        count += f[x[i - 1]][x[i]];
    }
    res = min(res, count);
}
void Try(int i) {
    
    for (int j = 1; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            x[i] = j;

            if (i == n) {
                check();
            } else {
                Try(i + 1);
            }
            visited[j] = false;
        }
    }
}
void testCase() {
    
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            f[i][j] = count(s[i], s[j]);
            f[j][i] = f[i][j];
        }
    }
    Try(1);
    cout << res;

}