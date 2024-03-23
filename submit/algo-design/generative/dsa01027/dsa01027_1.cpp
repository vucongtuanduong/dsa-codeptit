#include <bits/stdc++.h>
using namespace std;
int a[101], n;
int x[101];
bool ok;
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
    int j = n - 1;
    while (j > 0 && a[j] > a[j + 1]) {
        j--;
    }
    if (j > 0) {
        int k = n;
        while (a[k] < a[j]) {
            k--;
        }
        swap(a[k], a[j]);
        int l = j + 1, r = n;
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
    for (int i = 1; i <= n; i++) {
        cout << x[a[i]] << " ";
    }
    cout << endl;
}
void init() {
    cin >> n;
    ok = true;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        a[i] = i;
    }
    sort(x + 1, x + n + 1);
}