#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
    int climbStairs(int n) {
        return dp(n);
    }
};
int main() {
    // Write your code here
    int n;
    cin >> n;
    Solution h;
    cout << h.climbStairs(n) << endl;
    return 0;
}
