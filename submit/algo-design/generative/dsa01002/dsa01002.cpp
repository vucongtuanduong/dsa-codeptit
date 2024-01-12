#include <iostream>
using namespace std;
void testCase();
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
    int *x = new int[k + 1];
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    int t = k;
    while (x[t] == (n - k + t)) {
        t--;
    }
    if (t == 0) {
        for (int i = 1; i <= k; i++) {
            cout << i << " ";
        }
    } else {
        x[t]++;
        for (int i = t + 1; i <= k; i++) {
            x[i] = x[i - 1] + 1;
        }
        for (int i = 1; i <= k; i++) {
            cout << x[i] << " ";
        }
    }
}
