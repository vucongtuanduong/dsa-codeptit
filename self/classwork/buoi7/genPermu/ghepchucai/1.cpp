#include <bits/stdc++.h>
using namespace std;
int a[101],  n;
char c;
void init();
void display();
void genNext();
bool isFinal();
int main () {
    init();
    cout << c;
    // while (!isFinal()) {
    //     display();
    //     genNext();
    // }
    // display();
    return 0;
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
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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