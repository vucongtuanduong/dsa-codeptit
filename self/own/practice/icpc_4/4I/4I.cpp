#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    long long n, k;
    cin >> n >> k;
    // int res = 0;
    // for (int i = k; i <= n - 1; i++) {
    //     for (int j = i + 1; j <= n; j++) {
    //         int x = (n - i) / (j) ;
    //         x++;
    //         // cout << x << " ";
    //         res += x;
    //     }
    // }
    // // cout << endl;
    // cout << res;

    long long x = n - k;
    long long res = (x * (x + 1)) / 2;
    for (long long i = k; i <= n; i++) {
        long long temp = (n - k) / (i + 1);
        res += temp;
    }
    cout << res;
    return 0;
}
