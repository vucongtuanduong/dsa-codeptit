#include <bits/stdc++.h>
using namespace std;
int n, res;
int x[101];
int a[101];
bool xuoi[101], nguoc[101];
void testCase();
void init();
void Try(int i);
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
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!a[j] && !xuoi[i + j - 1] && !nguoc[i - j + n]) {
            x[i] = j;
            a[j] = true;
            xuoi[i + j - 1] = true;
            nguoc[i - j + n] = true;
            if (i == n) {
                res++;
            } else {
                Try(i + 1);
            }
            a[j] = false;
            xuoi[i + j - 1] = false;
            nguoc[i - j + n] = false;
        }
    }
}
void testCase() {
    cin >> n;
    init();
    Try(1);
    cout << res;
}
void init() {
    res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        a[i] = false;
        xuoi[i] = false;
        nguoc[i] = false;
    }
}