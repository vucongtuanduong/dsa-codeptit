## dsa05029
![alt text](image.png)
## Approach
This problem can be solved using dynamic programming. The idea is to count the number of ways to decode the message for each prefix of the message.

Here's the step-by-step plan:

1. Initialize a DP array of size `n+1` where `n` is the length of the message. `dp[i]` will store the number of ways to decode the first `i` characters of the message. Set `dp[0] = 1` because there is one way to decode an empty message.

2. Iterate over the message from left to right. For each character `i` from 1 to `n`, update `dp[i]` as follows:

   - If the `i-th` character is not '0', then it can be decoded alone, so add `dp[i-1]` to `dp[i]`.

   - If the `i-th` character and the previous character form a valid code (10 to 26), then they can be decoded together, so add `dp[i-2]` to `dp[i]`.

3. The answer will be `dp[n]`, which represents the number of ways to decode the whole message.

Here's the code that implements this plan:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string M;
        cin >> M;
        int n = M.size();
        int dp[n+1] = {0};
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (M[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            if (i > 1 && (M[i-2] == '1' || (M[i-2] == '2' && M[i-1] <= '6'))) {
                dp[i] += dp[i-2];
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
```

This code reads the number of test cases and for each test case, it reads the encoded message and calculates the number of ways to decode it. It then prints the result for each test case.

## Explain
Sure, let's break it down:

This problem is about decoding a message that has been encoded using a specific mapping: 'A'->1, 'B'->2, ..., 'Z'->26. The question is how many different ways the message can be decoded.

For example, if the message is "123", it can be decoded as "ABC" (1 2 3), "LC" (12 3), or "AW" (1 23). So there are 3 different ways to decode this message.

The key to solving this problem is to realize that the number of ways to decode a prefix of the message depends on the number of ways to decode the previous prefixes. This makes it a perfect candidate for dynamic programming, which is a technique for solving problems by breaking them down into smaller subproblems and reusing solutions to these subproblems to build solutions to larger problems.

Here's a more detailed explanation of the steps:

1. **Initialize a DP array:** We create an array `dp` of size `n+1` where `n` is the length of the message. The `i-th` element of this array (`dp[i]`) will store the number of ways to decode the first `i` characters of the message. We initialize `dp[0]` to 1 because there is one way to decode an empty message (do nothing).

2. **Iterate over the message:** For each character `i` from 1 to `n`, we consider how this character can be decoded.

3. **Update the DP array:** If the `i-th` character is not '0', then it can be decoded alone as a single letter, so we add `dp[i-1]` to `dp[i]`. If the `i-th` character and the previous character form a valid code (10 to 26), then they can be decoded together as a single letter, so we add `dp[i-2]` to `dp[i]`.

4. **Find the number of ways:** After considering all characters, the number of ways to decode the whole message will be `dp[n]`.

The reason why we use dynamic programming in this problem is that the decision to decode a character alone or together with the previous character depends on the decisions made for the previous characters. By storing the number of ways to decode each prefix in the `dp` array, we avoid recalculating the same values multiple times, which makes the algorithm more efficient.