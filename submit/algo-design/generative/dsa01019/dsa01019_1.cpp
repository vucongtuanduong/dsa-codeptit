#include <bits/stdc++.h>
using namespace std;
int n, a[101];
bool ok;
void testCase();
void init();
bool check();
void display();
void genNext();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        // cout << endl;
    }
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
    return true;

}
void display() {
    for(int i = 1; i <= n; i++) {
        if (a[i]) {
            cout << "H";
        } else {
            cout << "A";
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
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
    ok = true;
}
void testCase() {
    init();
    while(ok) {
        if (check()) {
            display();
        }
        genNext();
    }
}