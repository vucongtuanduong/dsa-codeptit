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

    if (k == 0) {
        long long res = n * n;
        cout << res;
        return 0;
    }
    long long x = n - k;
    long long res = (x * (x + 1)) / 2;
    for (long long i = k; i <= n; i++) {
        int j = i + 1;
        while (j <= (n - i)) {
            
            long long temp = (n - i) / (j);
            cout << "i: " << i << ", j: " << j << ", temp: " << temp << endl;
            res += temp;
            j++;
        }
        // long long temp = (n - k) / (i + 1);
        // res += temp;
    }
    cout << res;


    // long long count = 0;
    // for (long long i = 1; i <= n; i++) {
    //     for (long long j = 1; j <= n; j++) {
    //         if (i % j >= k) {
    //             cout << i << " " << j << endl;
    //             count++;
    //         }
    //     }
    // }
    // cout << endl << count << endl;
    return 0;
}
