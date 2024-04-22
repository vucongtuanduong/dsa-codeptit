#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[101];
void init();
void Try(int i);
void result();
int main () {
    init();
    Try(1);
    return 0;
}
void result() {
    for (int i =1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void init() {
    cin >> n >> k;
    x[0] = 0;
}
void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            result();
        } else {
            Try(i + 1);
        }
    }
}