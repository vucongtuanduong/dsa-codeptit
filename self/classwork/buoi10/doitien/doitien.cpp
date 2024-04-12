#include <bits/stdc++.h>
using namespace std;
int n, size;
int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
void testCase();
void init();
void greedy();
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
void greedy() {
    int tong = 0;
    for (int i = size - 1; i >= 0; i--) {
        tong += n / a[i];
        n %= a[i];
        if (n == 0) {
            break;
        }
    }
    cout << tong;
}
void init() {
    cin >> n;
    size = sizeof(a) / sizeof(int);
}
void testCase() {
    init();
    greedy();
}