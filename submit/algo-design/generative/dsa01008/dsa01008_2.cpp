#include <bits/stdc++.h>
using namespace std;
int a[101], n, k;
bool ok;
void init();
void display();
void genNext();
void testCase();
bool check();
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    
    return 0;
}
bool check() {
    int count1s = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            count1s ++;
        }
    }
    return (count1s == k);
}
void testCase() {
    init();
    while (ok) {
        display();
        genNext();
    }
}
void genNext() {
    int i = n;
    while (i > 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i > 0) {
        a[i] = 1;
    } else {
        ok = false;
    }
}
void display() {
    if (!check()) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}
void init() {
    cin >> n >> k;
    ok = true;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}