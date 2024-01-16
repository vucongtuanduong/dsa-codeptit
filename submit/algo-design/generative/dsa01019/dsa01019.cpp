#include <iostream>
using namespace std;
void testCase();
void Try(int *a, int n, int i);
bool check(int *a, int n);
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    // testCase();
    // Your code here
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n + 1];
    Try(a, n, 1);
}
void Try(int *a, int n, int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            // cout << "check: \n";
            if (check(a, n)) {
                for (int k = 1; k <= n; k++) {
                    if (a[k] == 1) {
                        cout << "H";
                    } else if(a[k] == 0) {
                        cout << "A";
                    }
                }
                cout << endl;
            }
        } else {
            Try(a, n, i + 1);
        }
    }
}
bool check(int *a, int n) {
    
    if (a[1] != 1) {
        return false;
    }
    if (a[n] != 0) {
        return false;
    }
    // int count0s = 0;
    bool is1 = true;
    for (int i = 2; i < n; i++) {
        // cout << "a[i]: " << a[i] << endl;
        if (a[i] == 1 && is1 == true) {
            return false;
        } else if (a[i] == 0) {
            is1 = false;
        } else if (a[i] == 1 && is1 == false) {
            is1 = true;
        }
    }
    // cout << "------\n";
    return true;
}