#include <iostream>
using namespace std;
void testCase();
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
void testCase() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        // currSum += a[i];
        sum -= a[i];
        if (i != 0) {
            if (currSum == sum) {
                cout << i + 1;
                return;
            }
        }
        currSum += a[i];
    }
    cout << -1; 

}