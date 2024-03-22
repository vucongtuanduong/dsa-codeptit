#include <bits/stdc++.h>
using namespace std;
int n, a[101], k;
int x[101];
void init();
bool isFinal();
void result();
void genNext();
int main () {
    
    init();
    while (!isFinal()) {
        result();
        genNext();
    }
    result();
    return 0;
}
void init() {
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
}
bool isFinal() {
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            return false;
        }
    }
    return true;
}
void result() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            sum += x[i];
        }
    }
    if (sum == k) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                cout << x[i] << " ";
            }
        }
        cout << endl;
    }
}
void genNext() {
    int t = n;
    while (a[t] == 1) {
        a[t] = 0;
        t--;
    }
    a[t] = 1;
}