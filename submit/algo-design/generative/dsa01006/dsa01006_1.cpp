#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<bool> used;
vector<vector<int>> res;
void testCase();
void Try(int i);
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
void Try(int i) {
    for (int j = 1; j <= a.size(); j++) {
        if (used[j] == false) {
            used[j] = true;
            a[i] = j;
            if (i == a.size() - 1) {
                res.push_back(a);
            } else {
                Try(i + 1);
            }
            used[j] = false;
        }
    }
}
void testCase() {
    a.clear();
    res.clear();
    int n;
    cin >> n;
    a.resize(n);
    used.resize(n, false);
    Try(0);
    for (int i = res.size() - 1; i >= 0; i--) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] ;
        }
        cout << " ";
    }
}