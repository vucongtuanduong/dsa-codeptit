#include <bits/stdc++.h>
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
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int checkSum = 0;
    for (int i = 0; i < n; i++) {
        
        sum -= a[i];
        if (i != 0) {
            if (checkSum == sum) {
                cout << i + 1;
                return;
            }
        }
        checkSum += a[i];
    }
    cout << "-1";
}
