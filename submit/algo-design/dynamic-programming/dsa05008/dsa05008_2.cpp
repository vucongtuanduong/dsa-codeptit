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
    vector<int> a(n);
    vector<int> sum(k + 1, 0);
    sum[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = k; j >= a[i]; j--) {
            if (sum[j - a[i]]) {
                sum[j] = 1;
            }
        }
    }
    if (sum[k]) {
        cout << "YES";
    } else {
        cout << "NO";
    }


}