#include <bits/stdc++.h>
using namespace std;
int y[101];
char x[101];
void testCase() {
    char a, b;
    cin  >> a >> b;
    if (b < a) {
        swap(a, b);
    }
    // cout << a << " " << b;
    int n = b -  a + 1;
    
    for (int i = 0; i < n; i++) {
        x[i] = i + a;
    }
    for (int i = 0; i < n; i++) {
        cout << (x[i]) << " ";
    }
    
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
