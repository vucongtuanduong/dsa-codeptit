#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
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
    long long res = 0;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++){ 
        res = (res + ((i * a[i]) % MOD)) % MOD;
    }
    cout << res;
}