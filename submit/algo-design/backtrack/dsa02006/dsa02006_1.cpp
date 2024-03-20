#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a, b;
void testCase();
void Try(int sum);
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
void Try(int sum) {
    
}
void testCase() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Try(k);
}