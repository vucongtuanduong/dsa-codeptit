#include <iostream>
#include <algorithm>
using namespace std;
void testCase();
void Try(int *x, int *a, int n, int i, bool *unused);
int main() {
    // Your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int *x = new int[n + 1];
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    bool *unused = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
    Try(x, a, n, 1, unused);

}
void Try(int *x, int *a, int n, int i, bool *unused) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            a[i] = j;
            unused[j] = false;
            if (i == n) {
                for (int k = 1; k <= n; k++) {
                    cout << x[a[k]] << " ";
                }
                cout << endl;
            } else {
                Try(x, a, n, i + 1, unused);
            }
            unused[j] = true;
        }
    }
}
