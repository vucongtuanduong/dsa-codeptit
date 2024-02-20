#include <iostream>
#include <climits>
using namespace std;
void testCase();
int maxSubArraySum(int *a, int l, int h);
int maxCrossingSum(int *a, int l, int m, int h);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
int maxCrossingSum(int *a, int l, int m, int h) {
    int sum = 0;
    int leftSum = INT_MIN, rightSum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + a[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    for (int i = m + 1; i <= h; i++) {
        sum += a[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}
int maxSubArraySum(int *a, int l, int h) {
    if (l == h) {
        return a[l];
    }
    int m = (l + h) / 2;
    return max(max(maxSubArraySum(a, l, m), maxSubArraySum(a, m + 1, h)), maxCrossingSum(a, l, m, h));
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxSubArraySum(a, 0, n - 1);
}