#include <bits/stdc++.h>
using namespace std;
int k;
string s;
int n;
string input;
map<string, int> mp;
int x[101];
void testCase();
void Try(int i);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void Try(int i) {
    for (int j = x[i - 1] + 1; j <= (n - k + i); j++) {
        x[i] = j;
        if (i == k) {
            string temp = "";
            for (int t = 1; t <= k; t++) {
                temp += s[x[t] - 1];
                // cout << temp;
            }
            mp[temp]++;
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    cin >> s >> k;
    n  = s.size();
    mp.clear();
    x[0] = 0;
    for (int i = 1; i <= k; i++) {
        x[i] = i;
    }
    Try(1);
    for(auto temp : mp) {
        cout << temp.first << endl;
    }
    mp.clear();
}
