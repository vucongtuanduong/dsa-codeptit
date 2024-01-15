#include <iostream>
using namespace std;
void testCase();
void Try(int *x, int n, int k, int i);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    // cout << n << k << endl;;
    int *x = new int[k + 1];
    x[0] = 0;
    Try(x, n, k, 1);

}
void Try(int *x, int n, int k, int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            for (int l = 1; l <= k; l++) {
                char c = x[l] + 'A' - 1;
                cout << c;
            }
            cout << endl;
            // continue;
        } else {
            Try(x, n, k, i + 1);
        }
    }
}
