## dsa07004
![alt text](image.png)
## Approach
**Problem Analysis:**

The problem is asking to find the minimum number of bracket reversals needed to make an expression balanced. A bracket expression is said to be balanced if it can be represented in the form (T) where T is a valid expression. A valid expression is a null string or an expression represented in the form TT or (T).

**Solution Analysis:**

The solution to this problem involves using a stack data structure. We iterate through the string and for every character:
- If it is an opening bracket, we push it to the stack.
- If it is a closing bracket and the stack is not empty and the top of the stack is an opening bracket, we pop from the stack.
- If it is a closing bracket and the stack is empty or the top of the stack is a closing bracket, we push it to the stack.

After iterating through the string, the stack will contain unbalanced brackets. We count the number of opening and closing brackets and calculate the answer as (ceil(open/2) + ceil(close/2)).

**Implementation in C++:**

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        stack<char> st;
        for (char c : S) {
            if (!st.empty() && st.top() == '(' && c == ')') {
                st.pop();
            } else {
                st.push(c);
            }
        }
        int open = 0, close = 0;
        while (!st.empty()) {
            if (st.top() == '(') {
                open++;
            } else {
                close++;
            }
            st.pop();
        }
        int ans = (open + 1) / 2 + (close + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}
```

**Time Complexity Analysis:**

The time complexity of the solution is O(n) where n is the length of the string. The space complexity is O(n) for the stack.
