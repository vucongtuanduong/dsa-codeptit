#include <bits/stdc++.h>
using namespace std;
void testCase() {
    
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i  = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = k - a[i] - a[j];
            int index =  upper_bound(a + j + 1, a + n, x) - lower_bound(a + j + 1, a + n, x);
            if (index > 0) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}
int main() {
    // Write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)  {
        testCase();
        cout << endl;
    }
    return 0;
}
