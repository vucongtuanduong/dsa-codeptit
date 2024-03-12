#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxSum(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return arr[0];
    vector<long long> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
    }
    return dp[n-1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << maxSum(arr) << endl;
    }
    return 0;
}