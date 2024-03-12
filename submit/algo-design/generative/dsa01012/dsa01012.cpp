#include <iostream>
using namespace std;
void testCase();
void Try(int i, int *a, int n);
void result(int *a, int n);
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
void result(int *a, int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == 1) {
            cout << 1 - a[i];
        } else {
            cout << a[i];
        }
    }
    cout << " ";
}
void testCase() {
    int n;
    cin >> n;
    int a[n + 1] = {0};
    Try(1, a, n);
}
void Try(int i, int *a, int n) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            result(a, n);
        } else {
            Try(i + 1, a, n);
        }
    }
}