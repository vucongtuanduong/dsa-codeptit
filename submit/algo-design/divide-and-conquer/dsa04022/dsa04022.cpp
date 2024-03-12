#include <iostream>
using namespace std;
long long f[30];
void prepare();
void testCase();
long long powll(long long a, long long b);
char find(long long n, long long k);
int main() {
    // Write your code here
    int t;
    cin >> t;
    prepare();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
long long powll(long long a, long long b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    }
    long long res = powll(a, b / 2);
    if (b % 2 == 0) {
        return (res  * res);

    } else {
        return (res * res * a);
    }
}
char find(long long n, long long k) {
    long long position_of_largest_num = powll(2, n - 1);
    if (k == position_of_largest_num) {
        return n + 'A' - 1;

    } else if (k < position_of_largest_num) {
        return find(n - 1, k);
    } 
    return find(n - 1, k - position_of_largest_num);
}
void testCase() {
    long long n, k;
    cin >> n >> k;
    // for (int i = n; i >= 1; i--) {
    //     if (k > f[i]) {
    //         k -= f[i];
    //     } else if (k == f[i]) {
    //         char res = 'A' + i - 1;
    //         cout << res;
    //         return;
    //     }
    // }

    cout << find(n, k);
}
void prepare() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < 30; i++) {
        f[i] = f[i - 1] * 2;
    }
}
