#include <bits/stdc++.h>
using namespace std;
int b[100];
int n, k;
long long ans;
long long a[92];
void init() {
    a[0] = 0;
    a[1] = 1;
    for (int j = 2; j <= 92; j++) {
        a[j] = a[j - 1] + a[j - 2];
    }
}
bool kiemtra(long long i) {
    for (int j = 1; j <= 92; j++) {
        if (i == a[j]) {
            return true;
        }
    }
    return false;
}
void Try(int u) {
    for (int j = b[u - 1] + 1; j <= n - k + u; j++) {
        b[u] = j;
        if (u == k) {
            ans++;
            if (kiemtra(ans)) {
                cout << ans << ": ";
                for (int h = 1; h <= k; h++) {
                    cout << b[h] << " ";
                }
                cout << endl;
            }
        } else {
            Try(u + 1);
        }
    }
}
int main() {
    init();
    cin >> n >> k;
    Try(1);
    return 0;
}
