#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101];
bool unused[101];
void result() {
    for (int i= 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (j != m) {
            if (unused[j]) {
                unused[j] = false;
                a[i] = j;
                if (i == n - 1) {
                    result();
                } else {
                    Try(i + 1);
                }
                unused[j] = true;
            }
        }
    }
}
void testCase() {
    cin >> n >> m;
    a[n] = m;
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
    Try(1);

}
int main() {
    // Write your code here
    // int t;
    // cin >> t;
    // while (t--) {
    //     testCase();
    //     cout << endl;
    // }
    testCase();
    return 0;
}
