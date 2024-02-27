#include <iostream>
using namespace std;
void testCase();//0.03s
void testCase2();//faster: 0.01s vs 0.03s
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}
void testCase2() {
    int n, s;
    cin >> n >> s;
    int a[n];
    int f[s + 1] = {};
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = s; j >= a[i]; j--) {
            if (f[j - a[i]] == 1) {
                f[j] = 1;
            }
        }
    }
    cout << ((f[s] == 1) ? "YES": "NO");
}
void testCase() {
    int n, s;
    cin >> n >> s;
    int a[n];
    int f[s + 1] = {};
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = s; j >= 1; j--) {
            if (j >= a[i] && f[j] == 0 && f[j - a[i]] == 1) {
                f[j] = 1;
            }
        }
    }
    cout << ((f[s] == 1) ? "YES": "NO");
}