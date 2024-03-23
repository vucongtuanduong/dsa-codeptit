#include <bits/stdc++.h>
using namespace std;
int a[101], n, k;
int x[101];
set<int> se;
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
    int t = k;
    while (t > 0 && a[t] == (n - k + t)) {
        t--;
    }
    if (t <= 0) {
        ok = false;
        return;
    }
    a[t]++;
    for (int i = t + 1; i <= k; i++) {
        a[i] = a[i - 1] + 1;
    }
}
void display() {
    for (int i = 1; i <= k; i++) {
        cout << x[a[i]] << " ";
    }
    cout << endl;
}
void init() {
    cin >> n >> k;
    ok = true;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        se.insert(x[i]);
    }
    int j = 1;
    for (auto temp : se) {
        x[j++] = temp;
    }
    n = se.size();
    for (int i  = 1; i <= k; i++) {
        a[i] = i;
    }
}