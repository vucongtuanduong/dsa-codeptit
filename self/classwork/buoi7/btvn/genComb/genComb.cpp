#include <bits/stdc++.h>
using namespace std;
int a[101], n, k;
bool ok = true;
void init();
void display();
void genNext();
int main () {
    init();
    while (ok) {
        display();
        genNext();
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
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void init() {
    cin >> n >> k;
    for (int i  = 1; i <= k; i++) {
        a[i] = i;
    }
}