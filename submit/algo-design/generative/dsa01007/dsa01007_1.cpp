#include <bits/stdc++.h>
using namespace std;
int a[11];
int n;
void testCase();
void Try(int i);
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
    
    cin >> n;
    Try(1);
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            for (int k = 1; k <= n; k++) {
                if (a[k] == 0) {
                    cout << "A";
                } else {
                    cout << "B";
                }
            }
            cout << " ";
        } else {
            Try(i + 1);
        }
    }
}