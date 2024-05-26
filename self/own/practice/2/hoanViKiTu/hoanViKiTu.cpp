#include <bits/stdc++.h>
using namespace std;
int y[101];
char x[101];
int n;
bool unused[101];
void result() {
    for (int j = 1; j <= n; j++ ) {
        cout << x[y[j] - 1] ;
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            unused[j] = false;
            y[i] = j;
            if (i == n) {
                result();
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}
void testCase() {
    char a, b;
    cin  >> a >> b;
    if (b < a) {
        swap(a, b);
    }
    // cout << a << " " << b;
    n = b -  a + 1;
    
    for (int i = 0; i < n; i++) {
        x[i] = i + a;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << (x[i]) << " ";
    // }
    for (int i = 1; i <= n; i++ ) {
        y[i] = i;
        unused[i] = true;
    }
    Try(1);
    
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
