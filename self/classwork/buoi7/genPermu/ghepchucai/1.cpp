#include <bits/stdc++.h>
using namespace std;
int a[101],  n;
char c;
bool ok = true;
void init();
void display();
void genNext();
bool check(int x);
int main () {
    init();
    while (ok) {
        display();
        genNext();
    }
    return 0;
}

bool check(int x) {
    return (x != 1) && (x != 5);
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
        swap(a[j], a[k]);
        int l  = j + 1, r = n;
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
    
    for (int i= 2; i < n; i++) {
        if (!check(a[i]) && check(a[i - 1]) && check(a[i + 1])) {
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (char)(a[i] + 'A' - 1) ;
    }
    cout << endl;
    
}
void init() {
    cin >> c;

    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}