#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[101];
bool ok;
set<int> se;
int res;
void testCase();
void init();
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
void init() {
    ok = true;
    res = 0;
    se.clear();
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
        se.insert(x[i]);
    }
}
void genNext() {
    int i = k;
    while (i > 0 && x[i] == (n - k + i)) {
        i--;
    }
    if (i > 0) {
        x[i]++;
        for (int j = i + 1; j <= k; j++) {
            x[j] = x[j - 1] + 1;
        }
    } else {
        ok  = false;
    }
}
void testCase() {
    init();
    genNext();
    if (!ok) {
        cout << k;
        return;
    }
    for (int i = 1; i <= k; i++) {
        if (se.count(x[i]) != 1) {
            res++;
        }
    }
    cout << res;
}