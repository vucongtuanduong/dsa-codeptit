## dsa05008
![alt text](image.png)


## Approach
This problem can be solved using dynamic programming. The idea is to create a boolean DP table where `dp[i][j]` is `true` if there is a subset of the first `i` elements that sums up to `j`, and `false` otherwise.

Here's a step-by-step explanation of how to solve this problem:

1. **Analyse the problem:** We need to find whether there is a subset of the given array that sums up to a given value `S`.

2. **Thinking chain to come up with the solution:** We can solve this problem by using dynamic programming. We create a boolean DP table where `dp[i][j]` is `true` if there is a subset of the first `i` elements that sums up to `j`, and `false` otherwise. We initialize `dp[i][0]` to `true` for all `i` because there is always an empty subset that sums up to `0`. We then fill up the rest of the DP table by considering each element either in the subset (if it is not greater than the current sum) or not in the subset. If we find a `true` value at `dp[n][S]`, we return `YES`, otherwise we return `NO`.

3. **Implement in C++:** 

```cpp
#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n, S;
    cin >> n >> S;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(S + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][S])
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
```

4. **Analyse time complexity:** The time complexity of this solution is O(n*S), where `n` is the number of elements in the array and `S` is the target sum. This is because we are processing each sum from `1` to `S` for each of the `n` elements. The space complexity is also O(n*S) because we are storing the DP table of size `n+1` by `S+1`.