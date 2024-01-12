#include <iostream>
using namespace std;
void testCase();
void Try(int *x, int i, int n);
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
        if (x[i] == 0) {
            cout << 'A';
        } else {
            cout << 'B';
        }
    }
    cout << " ";
}
void testCase() {
    int n;
    cin >> n;
    int *x = new int[n + 1];
    Try(x, 1, n);
}
void Try(int *x, int i, int n) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            result(x, n);
        } else {
            Try(x, i + 1, n);
        }
    }
}
