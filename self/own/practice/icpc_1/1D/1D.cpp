#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, st, en, u, d;
    cin >> n >> st >> en >> u >> d;
    int tong = en - st;
    int y;
    int res = INT_MAX;
    if (st > n || en > n) {
        cout << "-1";
        return;
    }
    if (st > en && d == 0) {
        cout << "-1";
        return;
    }
    for (int x = 0; x <= 1e6; x++) {
        if (d != 0) {
            y = (u * x - tong) / (d);
            int mod = (u * x - tong) % (d);
            if (y > 0 && mod == 0) {
                // cout << "x: " << x << ", y: " << y << endl;
                res = min(res, x + y);
            }
            
        }
        
    }
    if (res == INT_MAX) {
        cout << "-1";
        return;
    }
    cout << res;
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
