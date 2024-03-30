#include <bits/stdc++.h>
using namespace std;
int n;
bool ok;
int a[101];
void testCase();
void init();
void display();
void genNext();
bool check();
int main() {
    // Write your code here
    testCase();
    return 0;
}
bool check() {
     if (a[1] == 0 || a[n] == 1) {
        return false;
    }
    bool is1 = true;
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] == 1 && is1 == true) {
            return false;
        } else if (a[i] == 1 && is1 == false) {
            is1 = true;
        } else if (a[i] == 0 && is1 == true) {
            is1 = false;
        }
    }
    bool is0 = false;
    int count0s = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0 && is0 == false) {
            count0s = 1;
            is0 = true;
        } else if (a[i] == 0 && is0 == true) {
            count0s++;
            if (count0s > 3) {
                return false;
            }
        } else if (a[i] == 1) {
            count0s = 0;
            is0 = false;
        }
    }
    if (count0s > 3) {
        return false;
    } else {
        return true;
    }

}
void init() {
    cin >> n;
    ok = true;
}

void display() {
    if (!check()) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cout << "8";
        } else {
            cout << "6";
        }
    }
    cout << endl;
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
void testCase() {
    
    init();
    while(ok) {
        display();
        genNext();
    }
    
}