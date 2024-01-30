#include <iostream>
#include <algorithm>
using namespace std;
void testCase();
void testCase2();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}
void testCase() {
    long long  n, k;
    cin >> n >> k;
    long long a[n];
    for (long long  i = 0; i < n; i++ ){
        cin >> a[i];
    }
    sort(a, a + n);
    long long  count = 0;
    for (long long  i = 0; i < n - 2; i++ ) {
        long long  j = i + 1, m = n - 1;
        while (j < m) {

            if (a[i] + a[j] + a[m] < k) {
                count += m - j;
                j++;
            } else {
                m--;
            }
        }
    }
    cout << count;
}
void testCase2() {
    long long  n, k;
    cin >> n >> k;
    long long a[n];
    for (long long  i = 0; i < n; i++ ){
        cin >> a[i];
    }
    sort(a, a + n);
    long long  count = 0;
    for (long long i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long x = k - a[i] - a[j];
            count += lower_bound(a + j + 1, a + n, x) - (a + j + 1);
        }
    }
    cout << count;
}