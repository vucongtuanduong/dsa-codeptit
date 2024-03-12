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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = 0;
    long long pairs = 0;
    while (i < n) {
        while (j < n && a[j] - a[i] < k) {
            j++;
        }
        pairs += j - i - 1;
        i++;
    }
    cout << pairs;

}