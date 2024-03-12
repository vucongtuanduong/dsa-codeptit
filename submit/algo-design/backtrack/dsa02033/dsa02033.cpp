#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
void testCase();
void Try(int i, int *a, int n, bool *unused);
void print(int *a, int n);
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
void print(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int x = abs(a[i] - a[i + 1]);
        if (x == 1) {
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}
void Try(int i, int *a, int n, bool *unused) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            unused[j] = false;
            a[i] = j;
            if (i == n){ 
                print(a, n);
            } else {
                Try(i + 1, a, n, unused);
            }
            unused[j] = true;
        }
    }
}
void testCase() {
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    bool unused[n + 1];
    memset(unused, true, sizeof(unused));
    Try(1, a, n, unused);
}