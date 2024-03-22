#include <bits/stdc++.h>
using namespace std;
int n, a[101], k;
bool ok = true;
void init();
void result();
void genNext();
int main () {
    init();
    while (ok) {
        result();
        genNext();
    }
    return 0;
}
void init() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
    
}
void result() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void genNext() {
    int t = k;
    while (t > 0 && a[t] == (n - k + t)) {
        t--;
    }
    if (t <= 0) {
        ok = false;
        return;
    }
    a[t] ++;
    for (int i = t + 1; i <= k; i++) {
        a[i] = a[i - 1] + 1;
    }
}