#include <iostream>
using namespace std;
void testCase();
void Try(int *x, int n, int k, int *np, int i);
void result(int *x, int *np, int n, int k);
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
    int *np = new int[n + 1];
    
    Try(x, n, k, np, 1);
}
void Try(int *x, int n, int k, int *np, int i) {
    for (int j = n - k + i; j >= x[i - 1] + 1; j--) {
        x[i] = j;
        if (i == k) {
            result(x, np, n, k);
        } else {
            Try(x, n, k, np, i + 1);
        }
    }
}
void result(int *x, int *np, int n, int k) {
    for (int i = 1; i <= n; i++) {
        np[i] = 0;
    }
    for (int i = 1; i <= k; i++) {
        np[x[i]] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << np[i];
    }
    cout << endl;
}
