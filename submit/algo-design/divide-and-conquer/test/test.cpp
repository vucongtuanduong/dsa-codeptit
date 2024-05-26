#include <bits/stdc++.h>
using namespace std;

char findCellType(long long n, long long k) {
    if (n == 1 && k == 1) return 'X';
    long long mid = pow(2, n - 2);
    if (k <= mid) return findCellType(n - 1, k);
    else return (findCellType(n - 1, k - mid) == 'X') ? 'Y' : 'X';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << findCellType(n, k) << endl;
    }
    return 0;
}