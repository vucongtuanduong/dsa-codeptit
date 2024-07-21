#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i  = 0; i < n; i++) {
        a[i] = i + 1;
    }
    reverse(a.begin(), a.end());
    for (int i =0;i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += ((i + 1) % a[i]);
    }
    cout << res;
    return 0;
}
