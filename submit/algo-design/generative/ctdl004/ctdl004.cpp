#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[102];
int x[102];
int res;
bool ok;
void init();
void testCase();
void genNext();
bool check();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void genNext() {
    int i = n;
    while (i > 0 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if (i > 0) {
        x[i] = 1;
    } else {
        ok = false;
    }
}
bool check() {
    int count1s = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i]) {
            count1s ++;
        }
    }
    if (count1s != k) {
        return false;
    }
    int curr = INT_MIN;
    for (int i = 1; i <= n; i++) {
        // cout << a[i] << " ";
        if (x[i]) {
            if (a[i] > curr) {
                curr = a[i];
            } else {
                return false;
            }
        }
        // cout << endl;
    }
    return true;
}
void init() {
    res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x[i]= 0;
    }
    ok = true;
}
void testCase() {
    init();
    while (ok) {
        
        genNext();
        if (check()) {
            res++;
        }

    }
    cout << res;
    
}