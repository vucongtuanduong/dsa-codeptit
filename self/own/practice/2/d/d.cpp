#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> b;
void result() {
    for (int i = 0; i < n; i++ ){
        cout << (char)(a[i] + 'A' - 1);
    }
    for (int i = 0; i < n; i++ ){
        cout << b[i];
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        b[i] = j;
        if (i == n - 1) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    
    cin >> n;
    a.resize(n);
    b.resize(n);
    
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    // next_permutation(a.begin(), a.end());
    // for (auto x : a) {
    //     cout << x << " ";
    // }
    // cout << endl;
    do {
        Try(0);
    }while(next_permutation(a.begin(), a.end()));
    // while(next_permutation(a.begin(), a.end())) {
    //     Try(0);
    // }
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
