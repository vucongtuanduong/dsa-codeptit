#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int n= word.size();
        vector<int> dp(n);
        dp[0] = 2;
        for (int i = 1; i < n; i++) {
            if (word[i] > word[i - 1]) {
                dp[i] = dp[i - 1] - 1;
            } else {
                dp[i] = dp[i - 1] + 2;
            }
        }
        return dp[n - 1];
    }
};
void testCase() {
    string s;
    cin >> s;
    Solution h;
    cout << h.addMinimum(s);
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
