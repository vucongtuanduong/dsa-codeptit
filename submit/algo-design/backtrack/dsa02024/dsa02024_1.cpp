#include <bits/stdc++.h>
using namespace std;
void testCase();
void Try(vector<int> a, vector<int>&res, int start);
int main() {
    // Write your code here
    // int t;
    // cin >> t;
    // while (t--) {
    //     testCase();
    //     cout << endl;
    // }
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // sort(a.begin(), a.end());
    vector<int> res;
    Try(a, res, 0);
}
void Try(vector<int> a, vector<int>&res, int start) {
    if (res.size() > 1 ) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = start; i < a.size(); i++) {
            res.push_back(a[i]);
            Try(a, res, i + 1);
            res.pop_back();
        }
    }
}