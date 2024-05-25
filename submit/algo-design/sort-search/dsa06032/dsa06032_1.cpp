#include <bits/stdc++.h>
using namespace std;
void testCase() {
    long long n, k;
    cin >> n >> k;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long x = k - a[i] - a[j];
            cnt += lower_bound(a + j + 1, a + n, x) - (a + j + 1);
        }
    }
    cout << cnt;
}
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
