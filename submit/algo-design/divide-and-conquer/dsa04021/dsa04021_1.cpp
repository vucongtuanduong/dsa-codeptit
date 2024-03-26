#include <bits/stdc++.h>
using namespace std;
long long fibo[100];
void testCase();
void init();
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
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 100; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

}
void testCase() {
    long long n, k;
    cin >> n >> k;
    while (true) {
        if (n == 1 || n == 2) {
            if (n == 1) cout << "0";
            else cout << "1";
            return;
        }
        if (k > fibo[n - 2]) {
            k -= fibo[n - 2];
            n--;
        }
        else {
            n -= 2;
        }
            
    }
}  