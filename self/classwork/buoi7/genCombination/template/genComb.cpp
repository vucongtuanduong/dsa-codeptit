#include <bits/stdc++.h>
using namespace std;
int n, a[101], k;
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
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
    
}
bool isFinal() {
    for (int i = 1; i <= k; i++) {
        if (a[i] != (n - k + i)) {
            return false;
        }
    }
    return true;
}
void result() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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