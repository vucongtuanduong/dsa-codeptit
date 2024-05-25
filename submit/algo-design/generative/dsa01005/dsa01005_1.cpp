#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
bool unused[101];
void result() {
    for (int i = 1;i <= n; i++) {
        cout << a[i];
    }
    cout << " ";
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        unused[i] = true;
    }
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            unused[j] = false;
            a[i] = j;
            if (i == n) {
                result();
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}
void testCase() {
    init();
    Try(1);
}
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
