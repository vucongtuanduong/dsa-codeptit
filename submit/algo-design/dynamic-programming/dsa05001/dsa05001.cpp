#include <iostream>
#include <cstring>
using namespace std;
void testCase();
int f[1001][1001];
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
void testCase() {
    string s1, s2;
    cin >> s1 >> s2;
    int res = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
            res = max(res, f[i][j]);
        }

    }
    cout << res;
}