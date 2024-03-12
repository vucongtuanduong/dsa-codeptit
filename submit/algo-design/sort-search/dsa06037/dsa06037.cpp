#include <iostream>
#include <vector>
using namespace std;
void testCase();
int main() {
    // Your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int leftMax[n], rightMin[n];
    leftMax[0] = a[0];
    rightMin[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], a[i]);
    }
    vector<int> res;
    for (int i = 0; i < n - 1; i++ ) {
        if (leftMax[i] <= rightMin[i + 1]) { //m index so we must compare leftMax[i] to rightMin[i + 1]
            res.push_back(i + 1);
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}