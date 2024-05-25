#include <bits/stdc++.h>
using namespace std;
void testCase(){
    int n,  k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        int x = k - a[i];
        int index =  upper_bound(a + i + 1, a + n, x) - lower_bound(a + i + 1, a + n, x);
        if (index >= 0) {
            cnt += index;
        }
    }
    cout << cnt;
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
