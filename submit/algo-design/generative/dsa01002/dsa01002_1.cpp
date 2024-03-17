#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
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
    int count = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] == (n - k + i)) {
            count++;
        }
    }
    if (count == k) {
        for (int i = 1; i<= k; i++) {
            cout << i << " ";
        }
        return;
    } else {
        int i = k;
        while (a[i] == (n - k + i)) {
            i--;
        }
        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        } 
        for (int j = 1; j <= k; j++) {
            cout << a[j] << " ";
        }
    }
}