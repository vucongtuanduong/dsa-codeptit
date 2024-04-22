#include <bits/stdc++.h>
using namespace std;
int n, sum;
bool ok;
vector<int> a;
void testCase();
void init();
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
void init() {
    cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}
void testCase() {
    
    

}