#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
void result() {
    cout << a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] == 1) {
            cout << 1 - a[i];
        } else {
            cout << a[i];
        }
    }
    cout << " ";
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == a.size() - 1) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void testCase( ){
    
    cin >> n;
    a.resize(n);
    Try(0);
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
