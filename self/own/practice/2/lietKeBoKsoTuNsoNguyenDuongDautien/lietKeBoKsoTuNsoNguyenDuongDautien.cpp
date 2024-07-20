#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
void result() {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}
void Try(int i) {
    int start;
    if (i == 0) {
        start = 1;
    } else {
        start = a[i - 1];
    }
    for (int j = start; j <= n; j++) {
        a[i] = j;
        if (i == k - 1) {
            result();
        } else {
            Try(i + 1);
        }
        
    }
}
int main() {
    // Write your code here
    cin >> n >> k;
    a.resize(k);
    Try(0);
    return 0;
}
