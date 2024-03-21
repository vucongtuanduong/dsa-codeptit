#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    k = min(k, n - k);
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long count1 = 0, count2 = 0;
    for (int i = 0; i < k; i++) {
        count1 += a[i];
    }
    for (int i = k ; i < n; i++) {
        count2 += a[i];
    }
    if (count1 >= count2) {
        cout << count1 - count2;
    } else {
        cout << count2 - count1;
    }
}   