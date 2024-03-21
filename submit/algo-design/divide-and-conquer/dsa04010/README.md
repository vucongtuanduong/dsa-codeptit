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


## Divide and conquer approach
The problem can be solved using a divide and conquer approach. The idea is to divide the array into two halves and find the maximum subarray sum in them separately. Then, we find the maximum subarray sum that crosses the midpoint and take the maximum of the three sums.

Here's how to implement it in C++:

1. **Analyse the problem:** We need to find a contiguous subarray with the maximum sum. The array can contain both positive and negative integers.

2. **Thinking chain to come up with the solution:** We can solve this problem using a divide and conquer approach. The idea is to divide the array into two halves and find the maximum subarray sum in them separately. Then, we find the maximum subarray sum that crosses the midpoint and take the maximum of the three sums.

3. **Implement in C++:** 

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int> arr, int l, int m, int h) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
    return max(left_sum + right_sum, max(left_sum, right_sum));
}

int maxSubArraySum(vector<int> arr, int l, int h) {
    if (l == h)
        return arr[l];
    int m = (l + h) / 2;
    return max(maxSubArraySum(arr, l, m),
               max(maxSubArraySum(arr, m+1, h),
               maxCrossingSum(arr, l, m, h)));
}

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i= 0;i < n; i++) {
        cin >> a[i];
    }
    int max_sum = maxSubArraySum(a, 0, n-1);
    cout << max_sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
```

4. **Analyse time complexity:** The time complexity of this solution is O(N log N), where N is the number of elements in the array. This is because we are dividing the array into two halves in each recursive call, leading to a logarithmic number of levels, and processing each level takes linear time.