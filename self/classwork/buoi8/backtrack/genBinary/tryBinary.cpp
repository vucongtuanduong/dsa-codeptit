
#include <bits/stdc++.h>
using namespace std;
int n;
int x[101];
void init();
void Try(int i);
void result();
bool check();
int main () {
    init();
    Try(1);
    return 0;
}
bool check() {
    int l = 1, r = n;
    while (l <= r) {
        if (x[l] != x[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void init() {
    cin >> n;
}
void Try(int i) {
    for (int j = 0;  j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void result() {
    if (!check()) {
        return;
    }
    for (int i =1; i<= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}