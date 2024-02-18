#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void testCase();
void Try(int i, vector<int> &a, vector<int> &b, vector<vector<int>> &res);
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
    int n;
    cin >> n;
    vector<int> a, b;
    vector<vector<int>> res;
    a.resize(n);
    for (auto &x: a) {
        cin >> x;
    }
    Try(n, a, b, res);
    reverse(res.begin(), res.end());
    for (auto x : res) {
        cout << "[" ;
        for (int i = 0; i < x.size(); i++) {
            cout << x[i];
            if (i == x.size() - 1) {
                cout << "]";
            } else {
                cout << " ";
            }
        }
        cout << " ";
    }
    
}
void Try(int i, vector<int> &a, vector<int> &b, vector<vector<int>> &res) {
    res.push_back(a);
    if (i == 1) {
        return;
    }
    for (int j = 0; j < i - 1; j++) {
        b.push_back(a[j] + a[j + 1]);
    }
    a = b;
    a.resize(i - 1);
    b.clear();
    Try(i - 1, a, b, res);
}