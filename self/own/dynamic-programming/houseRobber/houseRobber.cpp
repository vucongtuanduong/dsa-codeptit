#include <bits/stdc++.h>
using namespace std;
//bottom-up approach
int dp1(vector<int> &nums, int i) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= n; i++ ) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[n];
}
//top-bottom approach:TLE
int dp(vector<int> &nums, int i) {
    if (i >= nums.size()) {
        return 0;
    }
    return max(dp(nums, i + 1), dp(nums, i + 2) + nums[i]);

}
int rob(vector<int> &nums) {
    int n = nums.size();
    int res = dp1(nums, 0);
    return res;
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    } 
    cout << rob(nums);
    return 0;
}
