#include <bits/stdc++.h>
using namespace std;
int n;
string res;
int a[101];
int x[101];
bool unused[101];
void testCase();
void init();
void TryChar(int i);
void TryNum(int i);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void TryChar(int i) {
    for (int j = 1; j <= n; j++)  {
        
    }
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
}
void testCase() {
    init();
    Try(a, 1);
    Try(x, 1);

}