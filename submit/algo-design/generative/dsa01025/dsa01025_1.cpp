#include <bits/stdc++.h>
using namespace std;
int n, k;
bool ok;
int x[101];
void testCase();
void init();
void genNext();
void display();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void init() {
    cin >> n >> k;
    ok =true;
    for (int i = 1; i <= k; i++) {
        x[i] = i;
    }
}
void genNext() {
    int i = k;
    while (i > 0 && x[i] == (n - k + i)) {
        i--;
    }
    if (i > 0) {
        x[i] ++;
        for (int j = i + 1; j <= k; j++) {
            x[j] = x[j - 1]  + 1;
        }
    } else {
        ok = false;
    }
    

}
void display() {
    for (int i = 1; i <= k; i++) {
        cout << (char)(x[i] + 'A' - 1);
    }
    cout << endl;
}
void testCase() {
    
    
    init();
    while (ok) {
        display();
        genNext();
    }

}