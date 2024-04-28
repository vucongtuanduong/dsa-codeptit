#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, s;
    cin >> n >> s;
    string minn = "", maxx = "";
    int i = 0;
    if (s == 0 && n == 1) {
        cout << "0 0";
        return;
    } else if (s < 1 || s > (9 * n)) {
        cout << "-1 -1";
        return;
    }
    while (n > 0) {
        if (s >= 9) {
            maxx += to_string(9);
            s -= 9;
        } else {
            maxx += to_string(s);
            s = 0;
        }
        n--;
    }
    minn = maxx;
    reverse(minn.begin(), minn.end());
    if (minn[0] == '0') {
            minn[0] = '1';
            int i = 1;
            while (minn[i] == '0') {
                i++;
            }
            minn[i] --;
        }
    // minn[0] = '1';
    cout << minn << " " << maxx;

}
int main() {
    // Write your code here
    testCase();
    return 0;
}