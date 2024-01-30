#include <iostream>
#include <vector>
using namespace std;
void testCase();
void init();
long long fibo[100];
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
void testCase() {
    long long n, k;
    cin >> n >> k;
    while (true) {
        if (n == 1 || n == 2) {
            if (n == 1) cout << "A";
            else cout << "B";
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
void init() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 100; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
