#include <bits/stdc++.h>
using namespace std;
void testCase(){ 
    int n, q;
    cin >> n >> q;
    int a[100] = {0};
    while (q--) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y + 1]--;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            cout << "0 ";
        } else {
            cout << "1 ";
        }
    }
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
