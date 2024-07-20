#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    vector<int> c, d;
    for (int i = 0; i < n; i++ ){
        cin >> a[i];
        if (a[i] % 2 == 0) {
            b[i] = 0;
            c.push_back(a[i]);
        } else {
            b[i] = 1;
            d.push_back(a[i]);
        }
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end(), greater<int>());
    // reverse(d.begin(), d.end());
    int cntEven = 0, cntOdd = 0;
    for (int i = 0; i < n; i++ ){
        if (b[i] == 0) {
            cout << c[cntEven++] << " ";
        } else {
            cout << d[cntOdd++] << " ";
        }
    }

}
int main() {
    // Write your code here
    testCase();
    return 0;
}
