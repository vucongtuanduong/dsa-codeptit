#include <iostream>
using namespace std;
void testCase();
bool isFinal(int *x, int n, int k);
int main() {
    // Your code here
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
    int *x = new int[n + 1];
    int *a = new int[n + 1];
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    int t = k;
    while (t > 0 && x[t] == (n - k + t)) {
        t--;
    }
    if (t == 0) {
        cout << k;
    } else {
        for (int i = 0; i < t; i++) {
            a[i] = x[i];
        }
        a[t] = x[t] + 1;
        for (int i = t + 1; i <= k; i++) {
            a[i] = a[i - 1] + 1;
        }
        int count = 0;
        for (int i = 1; i <= k; i++) {
            // cout << "a[i]: " << a[i]  << ", x[i]: " << x[i] << endl;
            bool ok = false;
            for (int j = 1; j <= k; j++) {
                if (a[j] == x[i]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                count++;
            }
        }
        cout << count;
    }

}
