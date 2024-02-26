#include <iostream>
#include <vector>
using namespace std;
void testCase();
void init();
long long f[55];
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void init() {
    f[0] = 0;
    f[1] = 1; 
    for (int i = 2; i < 55; i++) {
        f[i] = f[i - 1] * 2;
    }
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    for (int i = n; i >= 1; i--) {
        if (k > f[i]) {
            k -= f[i];
        } else if (k == f[i]) {
            cout << i ;
            return;
        }
    }
}