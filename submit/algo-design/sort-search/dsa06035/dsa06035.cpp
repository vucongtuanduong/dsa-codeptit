#include <iostream>
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
    int n;
    cin >> n;
    int a[100005] = {0};
    int l[100005] = {0}, r[100005] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            l[i] = l[i - 1] + 1;
        } else {
            l[i] = 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] > a[i + 1]) {
            r[i] = r[i + 1] + 1;
        } else {
            r[i] = 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, l[i] + r[i] - 1);
    }
    cout << res;
}