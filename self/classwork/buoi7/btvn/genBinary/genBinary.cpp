#include <bits/stdc++.h>
using namespace std;
int a[101],n;
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
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}