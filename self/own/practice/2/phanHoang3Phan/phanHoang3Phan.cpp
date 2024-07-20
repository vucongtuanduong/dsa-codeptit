#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    long long sum = 0;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << "0";
        return;
    }
    
    long long res = 0;
    
    for (int i = 0; i < n; i++) {
        int j = n - 1;
        while (i <> j) {
            long long sum1 = 0, sum2 = 0, sum3 = 0;
            for (int x = 0; x <= i; x++) {
                sum1 += a[x];
            }
            for (int y = n - 1; y >= j; y--) {
                sum2 += a[y];
            }
            sum3 = sum - sum1 - sum2;
            if (sum1 == sum2 && sum2 == sum3) {
                res++;
            }
            cout << "i: " << i << ", j: " << j << endl;
            cout << "sum1: " << sum1 << ", sum2: " << sum2 << ", sum3: " << sum3 << endl;
            // sum1 = sum2 = sum3 = 0;
            j--;
        }
    }
    cout << res;
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
