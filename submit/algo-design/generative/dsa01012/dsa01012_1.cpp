#include <bits/stdc++.h>
using namespace std;
vector<int>x;
int n;
bool ok;
void testCase();
void init();
void display();
void genNext();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void display() {
    cout << x[1];
    for (int i = 2; i <= n; i++){ 
        if (x[i - 1] == 1) {
            cout << 1 - x[i];
        } else {
            cout << x[i];
        }
    }
    cout << " ";
}
void genNext() {
    int i = n;
    while (i > 0 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if (i > 0) {
        x[i] = 1;
    } else {
        ok = false;
    }
}
void init() {
    cin >> n;
    ok = true;
    x.resize(n);
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }

}
void testCase() {
    init();
    while(ok) {
        display();
        genNext();
    }
}