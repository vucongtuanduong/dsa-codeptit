#include <bits/stdc++.h>
using namespace std;
void testCase();
void Try(vector<int>a, int i, int t, bool &check, int sum);
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
void Try(vector<int>a, int i, int t, bool &check, int sum) {
    if (check) {
        return;
    }
    if (t > sum) {
        return;

    }
    if (t == sum) {
        check = true;
        return;
    }
    for (int j = i; j < a.size(); j++) {
        Try(a, j + 1, t + a[j], check, sum);
    }
}
void testCase() {
    int sum = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    bool check = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 0) {
        sum /= 2;
        Try(a, 0, 0, check, sum);
        if (check) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}