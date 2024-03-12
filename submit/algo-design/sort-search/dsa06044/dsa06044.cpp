#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int x;
            cin >> x;
            a.push_back(x);
            // cin >> a[i];
        }
        else {
            int x;
            cin >> x;
            b.push_back(x);
            // cin >> b[i];
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int i = 0, j = 0;
    int n1 = a.size(), n2 = b.size();
    if (n % 2 == 0) {
        for (int i = 0; i < n1; i++) {
            cout << a[i] << " " << b[i] << " ";
        }
    } else {
        for (int i = 0; i < n1 - 1; i++) {
            cout << a[i] << " " << b[i] << " ";
        }
        cout << a[n1 - 1];
    }
}