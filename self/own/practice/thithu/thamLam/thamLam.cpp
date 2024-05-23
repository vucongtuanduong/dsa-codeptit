#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = n / k;
    int m = cnt;
    int i = 0;
    int sum = 0;
    while (k--) {
        for (int j = i + 1; j < i + m; j++) {
            sum += abs(a[j] - a[j - 1]);
        }
        i = i + m;
    }
    cout << sum << endl;
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
