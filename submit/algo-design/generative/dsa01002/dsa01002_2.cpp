#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, k;
    cin >> n >> k;
    int a[k + 1];
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] == (n - k + i)) {
            cnt++;
        }
    }
    // cout << cnt << endl;
    if (cnt == k) {
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
        return;
    }
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
