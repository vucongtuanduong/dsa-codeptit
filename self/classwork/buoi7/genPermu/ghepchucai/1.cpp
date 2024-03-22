#include <bits/stdc++.h>
using namespace std;
int a[101],  n;
char c;
void init();
void display();
void genNext();
bool isFinal();
bool check(int x);
bool check1();
int main () {
    init();
    while (!isFinal()) {
        display();
        genNext();
    }
    display();
    return 0;
}
bool check1() {
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 || a[i] == 5) {
            if (i > 1 && i < n && check(a[i -1]) && check(a[i + 1])) {
                return false;
            }
        }
        
        
    }
    return true;
}
bool check(int x) {
    return (x != 1) && (x != 5);
}
void genNext() {
    int j = n - 1;
    while (a[j] > a[j + 1]) {
        j--;
    }
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
}
bool isFinal() {
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return false;
        }
    }
    return true;
}
void display() {
    
    if (check1()) {
        for (int i = 1; i <= n; i++) {
            cout << (char)(a[i] + 'A' - 1) ;
        }
        cout << endl;
    }
    
}
void init() {
    cin >> c;

    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}