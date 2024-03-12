#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void testCase();
void Try(int i, int n, string &a, string &b, vector<bool> &unused);
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
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    string b;
    b.resize(n);
    sort(s.begin(), s.end());
    vector<bool> unused;
    unused.resize(n, false);
    Try(0, n, s, b, unused);

}
void Try(int i, int n, string &a, string &b, vector<bool> &unused) {
    for (int j = 0; j < n; j++) {
        if (!unused[j]) {
            b[i] = a[j];
            unused[j] = true;
            if (i == n - 1) {
                cout << b << " ";
            } else {
                Try(i + 1, n , a, b, unused);
            }
            unused[j] = false;
        }
    }
}