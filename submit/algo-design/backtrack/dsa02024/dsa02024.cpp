#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void testCase();
void Try(int i, string s, int count, vector<string> &res, int *a, int n);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<string> res;
    Try(0, "", 0, res, a, n);
    sort(res.begin(), res.end());
    for (auto x : res) {
        cout << x << endl;
    }
}
void Try(int i, string s, int count, vector<string> &res, int *a, int n) {
    for (int j = i + 1; j <= n; j++) {
        if (a[i] < a[j]) {
            if (count > 0) res.push_back(s + to_string(a[j]) + " ");
            Try(j, s + to_string(a[j]) + " ", count + 1, res, a, n);
        }
    }
}