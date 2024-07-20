#include <bits/stdc++.h>
using namespace std;
string s;
int n;
vector<int> a;
void testCase() {
    cin >> s;
    n = s.length();
    sort(s.begin(), s.end());
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    do{
        for (int i = 0; i < n; i++) {
            if (s[a[i]] == '0' && i == 0) {
                continue;
            }
            // cout << "\na[i]: " << a[i] << endl;
            cout << s[a[i]];
        }
        cout << endl;
    }while(next_permutation(a.begin(), a.end()));
    // for (int x : a) {
    //     cout << x << " ";
    // }
    // cout << endl;
}
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
