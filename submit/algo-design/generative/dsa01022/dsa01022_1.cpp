#include <bits/stdc++.h>
using namespace std;
int a[101], n, stt;
int x[101];
bool ok;
void init();
void display();
void genNext();
void testCase();
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    
    return 0;
}
void testCase() {
    init();
    while (ok) {
        display();
        genNext();
    }
    
}
void genNext() {
    int j = n - 1;
    while (j > 0 && a[j] > a[j + 1]) {
        j--;
    }
    if (j > 0) {
        int k = n;
        while (a[k] < a[j]) {
            k--;
        }
        swap(a[k], a[j]);
        int l = j + 1, r = n;
        while (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    } else {
        ok = false;
    }
}
void display() {
    stt++;
    for (int i = 1; i <= n; i++) {
        if (a[i] != x[i]) {
            return;
        }
    }
    cout << stt;
}
void init() {
    cin >> n;
    ok = true;
    stt = 0;
    for (int i  = 1; i <= n; i++) {
        cin >> x[i];
        a[i] = i;
    }
}