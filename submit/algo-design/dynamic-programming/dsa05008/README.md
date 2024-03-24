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



### dsa05008_2 explain
Your code is solving the problem by using a dynamic programming approach. Here's a detailed explanation:

1. **Input Reading:** The code first reads the number of test cases `t`. For each test case, it reads the number of elements `n` and the target sum `k`, and then reads the elements of the array `a`.

2. **Dynamic Programming Initialization:** The code initializes a DP array `sum` of size `k + 1` with all elements set to `0`, except `sum[0]` which is set to `1`. This is because there is always an empty subset with sum `0`.

3. **Dynamic Programming Calculation:** The code then fills up the DP array. For each element `a[i]` of the array, it iterates over the DP array from `k` to `a[i]` in reverse order. If `sum[j - a[i]]` is `1`, it sets `sum[j]` to `1`. This means that if there is a subset with sum `j - a[i]`, then there is also a subset with sum `j` (by including `a[i]` in the subset).

4. **Result Output:** Finally, the code checks `sum[k]`. If it is `1`, it prints `YES`, meaning there is a subset with sum `k`. Otherwise, it prints `NO`, meaning there is no such subset.

This algorithm works because it considers all possible subsets by including or excluding each element, and checks if there is a subset with sum `k`. The time complexity of this algorithm is O(n*k), where `n` is the number of elements and `k` is the target sum. This is because it processes each sum from `k` to `a[i]` for each of the `n` elements. The space complexity is O(k), as it uses a DP array of size `k + 1`.