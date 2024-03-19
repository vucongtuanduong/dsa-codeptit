## dsa05001
![alt text](image.png)

## Approach
**Problem Analysis:**

The problem is about finding the length of the longest common subsequence (LCS) of two strings. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. 

**Solution Analysis:**

The problem can be solved using dynamic programming. The idea is to create a 2D array `dp` where `dp[i][j]` is the length of the LCS of the first `i` characters of `S1` and the first `j` characters of `S2`. 

The algorithm is as follows:

1. Initialize a 2D array `dp` with dimensions `(n+1) x (m+1)`, where `n` and `m` are the lengths of `S1` and `S2` respectively. Set all elements of `dp` to 0.

2. For each character `S1[i]` and `S2[j]`:

   - If `S1[i]` is equal to `S2[j]`, then `dp[i][j] = dp[i-1][j-1] + 1` because we can extend the LCS of `S1[1..i-1]` and `S2[1..j-1]` by `S1[i]`.

   - If `S1[i]` is not equal to `S2[j]`, then `dp[i][j] = max(dp[i-1][j], dp[i][j-1])` because the LCS of `S1[1..i]` and `S2[1..j]` is either the LCS of `S1[1..i-1]` and `S2[1..j]` or the LCS of `S1[1..i]` and `S2[1..j-1]`.

3. The length of the LCS of `S1` and `S2` is `dp[n][m]`.

**Implementation in C++:**

```cpp
#include <bits/stdc++.h>
using namespace std;

void testCase() {
    string S1, S2;
    cin >> S1 >> S2;
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i-1] == S2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        testCase();
    }
    return 0;
}
```

**Time Complexity Analysis:**

The time complexity of the algorithm is O(n*m) because it involves a nested loop that iterates over the characters of `S1` and `S2`. Here, `n` and `m` are the lengths of `S1` and `S2` respectively.