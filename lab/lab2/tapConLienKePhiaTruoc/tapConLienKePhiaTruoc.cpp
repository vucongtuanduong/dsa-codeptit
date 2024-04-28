#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
vector<int> input;
vector<int> precedence;
bool ok = false;

void testCase() {
    cin >> n >> k;
    ok = false;
    a.resize(k + 1);
    input.resize(k + 1);
    precedence.resize(k + 1);
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] == i) {
            cnt++;
        }
    }
    if (cnt == k) {
        for (int i = 1; i <= k; i++ ){
            cout << (n - k + i) << " ";
        }
        return;
    } else {
        int i = k;
        while (i >= 1 && a[i] == a[i - 1] + 1) {
            i--;
        }
        // cout << "i: " << i << endl;
        if (i != 0) {
            a[i]--;
        }
        for (int j = i + 1; j <= k; j++) {
            a[j] = n - k + j;
        }
        for (int j = 1; j <= k; j++) {
            cout << a[j] << " ";
        }
    }
    // Try(1);
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
