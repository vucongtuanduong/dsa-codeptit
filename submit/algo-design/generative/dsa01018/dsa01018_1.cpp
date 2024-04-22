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
    int a[k + 1];
    int countCheck = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] == i) {
            countCheck++;
        }
    }
    if (countCheck == k) {
        for (int i = 1; i <= k; i++) {
            cout << (n - k + i) << " ";
        }
        return;
    } 
    int t = k;
    while (t > 0 && a[t] == a[t - 1] + 1) {
        t--;
    }
    a[t]--;
    for (int i = t + 1; i <= k; i++) {
        a[i] = n - k + i;
    }
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }

}