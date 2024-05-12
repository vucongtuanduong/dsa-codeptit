#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i>= 0; i--) {
            dp[i] = energy[i];
            if (i + k < n) {
                dp[i] += dp[i + k];
            }
        }
        for (auto x : dp) {
            cout << x << " ";
        }
        cout << endl;
        return *max_element(dp.begin(), dp.end());
    }
};
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    Solution h;
    cout << h.maximumEnergy(energy, k);
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
