#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[101];
void result() {
    for (int i = 1; i <= k; i++) {
        cout << a[i] ;
    } 
    cout << " ";
}
void Try(int i) {
    for (int j = a[i - 1] + 1; j <= (n - k + i); j++) {
        a[i] = j;
        if (i == k) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    
    cin >> n >> k;
    
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
    Try(1);

}
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
