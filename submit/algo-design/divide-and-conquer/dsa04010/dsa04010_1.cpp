#include <bits/stdc++.h>
using namespace std;
void testCase();
int maxSubArraySum(vector<int> a, int l, int r);
int maxCrossingSum(vector<int> a, int l, int m, int r);
int result(vector<int> a);
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
int maxCrossingSum(vector<int> a, int l, int m, int r) {
    int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += a[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        if(sum > right_sum) {
            right_sum = sum;
        }
    }
    return max(left_sum + right_sum, max(left_sum, right_sum));
}
int maxSubArraySum(vector<int> a, int l, int r) {
    if (l == r) {
        return a[l];
    }
    int m = (l + r) / 2;
    return max(maxCrossingSum(a, l,m, r), max(maxSubArraySum(a, l, m), maxSubArraySum(a, m+1, r)));
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i= 0;i < n; i++) {
        cin >> a[i];
    }
    // cout << maxSubArraySum(a, 0, n - 1);
    cout << result(a);
}
int result(vector<int> a) {
    int currentSum = 0, checkSum = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        currentSum += a[i];
        if (checkSum < currentSum) {
            checkSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return checkSum;

}