#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        map<int, int> mp;
        for (int j = 0; j < 5; j++) {
            if (mp[a[i][j]] == 1) {

            }
        }
    }
    return 0;
}
