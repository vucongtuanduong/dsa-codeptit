#include <bits/stdc++.h>
using namespace std;
int n, a[101], k;
set<int> se;
int res;
void init();
bool isFinal();
void result();
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
    if (isFinal()) {
        cout << k;
        return;
    }
    genNext();
    result();
}
void init() {
    res = 0;
    se.clear();
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
    
}
bool isFinal() {
    for (int i = 1; i <= k; i++) {
        if (a[i] != (n - k + i)) {
            return  false;
        }
    }
    return true;
}
void result() {
    for (int i = 1; i <= k; i++) {
        if (se.count(a[i]) != 1) {
            res++;
        }
    }
    cout << res;
}
void genNext() {
    int t = k;
    while (a[t] == (n - k + t)) {
        t--;
    }
    a[t] ++;
    for (int i = t + 1; i <= k; i++) {
        a[i] = a[i - 1] + 1;
    }
    
}