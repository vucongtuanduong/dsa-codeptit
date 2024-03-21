## dsa04010
![alt text](image.png)

## Approach
This problem is about finding the subarray with the maximum sum in an array of integers, which can include both positive and negative numbers. This is a common problem in computer science and is often solved using Kadane's algorithm.

Here's a step-by-step explanation of how to solve this problem:

1. **Analyse the problem:** We need to find a contiguous subarray with the maximum sum. The array can contain both positive and negative integers.

2. **Thinking chain to come up with the solution:** We can solve this problem using Kadane's algorithm. The idea is to maintain a running sum of the array and reset it to zero whenever it becomes negative. We also keep track of the maximum sum we have seen so far.

3. **Implement in C++:** 

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size) {
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << maxSubArraySum(A, N) << endl;
    }
    return 0;
}
```

4. **Analyse time complexity:** The time complexity of this solution is O(N), where N is the number of elements in the array. This is because we are processing each element of the array exactly once.