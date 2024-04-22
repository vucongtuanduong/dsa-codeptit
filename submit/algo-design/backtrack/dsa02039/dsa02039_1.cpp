#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
vector<vector<int>>res;
void testCase();
void Try(int sum, int maxNum);
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
void Try(int sum, int maxNum) {
    if (sum == 0) {
        res.push_back(a);
        return;
    }
    for (int i = min(sum, maxNum); i >= 1; i--) {
        a.push_back(i);
        Try(sum - i, i);
        a.pop_back();
    }
}
void testCase() {
    res.clear();
    cin >> n;
    Try(n, n);
    cout << res.size() << endl;
    for (auto x : res) {
        cout << "(";
        for (int i = 0; i < x.size(); i++) {
            cout << x[i];
            if (i != x.size() - 1) {
                cout << " ";
            }
        }
        cout << ") ";
    }
}