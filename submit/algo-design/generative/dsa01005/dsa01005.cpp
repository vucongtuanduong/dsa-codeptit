#include <iostream>
using namespace std;
void testCase();
void Try(int *x, int i, int n, bool *unused);
void result(int *x, int n);
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
void result(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << " ";
}
void testCase() {
    int n;
    cin >> n;
    int *x = new int[n + 1];
    bool *unused = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
    Try(x, 1, n, unused);
}
void Try(int *x, int i, int n, bool *unused) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            x[i] = j;
            unused[j] = false;
            if (i == n) {
                result(x, n);
            } else {
                Try(x, i + 1, n, unused);
            }
            unused[j] = true;
        }
    }
}
