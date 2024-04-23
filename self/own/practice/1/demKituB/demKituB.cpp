#include <bits/stdc++.h>
using namespace std;
long long fibo[50];
long long l[50];
void init(){ 
    f[0] = 0;
    f[1] = 1;
    l[0] = 1;
    l[1] = 1;
    for (int i = 2; i < 50; i++) {
        f[i] = f[i - 1] + f[i - 2];
        l[i] = l[i - 1] + l[i - 2];
    }

}
void testCase() {
    int n, k;
    cin >> n >> k;
    long long res  = 0;
    while (k > 0 && n > 0) {
        if (k == l[n]) {
            res += f[n];
            break;
        }
        if (k >= l[n - 1]) {
            res += f[n - 1];
            k -= l[n - 1];
            n -= 2;
        } else {
            n--;
        }
    }
    cout << res;
}
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
