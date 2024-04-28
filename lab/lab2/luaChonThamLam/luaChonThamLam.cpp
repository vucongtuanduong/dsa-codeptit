#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, s;
    cin >> n >> s;
    vector<int> minn(n, 0), maxx(n, 0);
    int i = 0;
    if (s >= 9 && n == 0) {
        cout << "-1 -1";
        return;
    }
    // if (s <= 9 && n > 1) {
    //     cout << "-1 -1";
    //     return;
    // } 
    // if (s <= 9 && n == 1) {
    //     cout << "9 9";
    //     return;
    // }
    if (s > (9 * n)) {
        cout << "-1 -1";
        return;
    }
    while (s > 0 && i < n) {
        if (s >= 9) {
            maxx[i] = 9;
            s -= 9;
        } else {
            maxx[i] = s;
            s = 0;
        }
        i++;
    }
    minn = maxx;
    reverse(minn.begin(), minn.end());
    if (minn[0] == 0) {
        int j = 0;
        while (j < n && minn[j] == 0) {
            j++; 
        }
        minn[j] -= 1;

    }
    minn[0] = 1;
    for (int i = 0; i < n; i++) {
        cout << minn[i];
    }
    cout << " ";
    for (int i = 0; i < n; i++) {
        cout << maxx[i];
    }

}
int main() {
    // Write your code here
    testCase();
    return 0;
}
