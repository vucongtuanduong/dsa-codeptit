#include <iostream>
#include <climits>
using namespace std;
int n;
int a[101];
void testCase();
void init();
int maxSubArray(int l, int r);
int maxCrossingSum(int l, int m, int r);
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
int maxCrossingSum(int l, int m, int r) {
    int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += a[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}
int maxSubArray(int l, int r) {
    if (l == r) {
        return a[l];
    }
    int m = (l + r) / 2;
    int maxLeft = maxSubArray(l, m);
    int maxRight = maxSubArray(m + 1, r);
    int maxLeftRight = maxCrossingSum(l, m, r);
    int maxValue = max(maxLeft, max(maxRight, maxLeftRight));
    return maxValue;
}
void testCase() {
    init();
    cout << maxSubArray(0, n - 1);
}
