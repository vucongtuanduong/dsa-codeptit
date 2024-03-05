#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void testCase();
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
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int b[n + 1];
    int ok = 0;
    map<int, int> mp;
    int count = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        mp[a[i]]++;
        b[i] = a[i];
        // cout << a[i] << " , n - k + i: " << n - k + i << endl;
        if (a[i] == (n - k + i)) {
            ok++;
        }
    }
    if (ok == k) {
        cout << k ;
        return;
    }
    int t = k;
    while (b[t] == (n - k + t)) {
        t--;
    }
    b[t]++;
    for (int i = t + 1; i <= k; i++) {
        b[i] = b[i - 1] + 1;
    }
    // for (int i =1; i <= k; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= k; i++) {
        if (mp[b[i]] >= 1) {
            count++;
        }
    }
    cout << k - count;
}