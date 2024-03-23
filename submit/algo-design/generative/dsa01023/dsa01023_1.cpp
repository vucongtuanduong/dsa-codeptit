#include <bits/stdc++.h>
using namespace std;
int a[101], n, k, stt;
int x[16];
bool ok;
void init();
void display();
void genNext();
int main () {
    int t;
    cin >> t;
    while (t--) {
        init();
        while (ok) {
            display();
            genNext();
        }
    }
    
    return 0;
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
    a[t]++;
    for (int i = t + 1; i <= k; i++) {
        a[i] = a[i - 1] + 1;
    }
}
void display() {
    stt++;
    for (int i = 1; i <= k; i++) {
        if (a[i] != x[i]) {
            return;
        }
    }
    cout << stt << endl;
    ok = false;
    return;
}
void init() {
    cin >> n >> k;
    ok = true;
    stt = 0;
    for (int i  = 1; i <= k; i++) {
        cin >> x[i];
        a[i] = i;
    }
}