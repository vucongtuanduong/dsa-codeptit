#include <bits/stdc++.h>
using namespace std;
bool ok  = false;
void testCase();
void findSubset(vector<int> a, vector<int> &res, int k, int start);
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    // Write your code here
    return 0;
}
void findSubset(vector<int> a, vector<int> &res, int k, int start) {
    if (k == 0) {
        cout << "[";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] ;
            ok = true;
            if (i != res.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    } else {
        for (int i = start; i < a.size(); i++) {
            res.push_back(a[i]);
            findSubset(a, res, k - a[i], i + 1);
            res.pop_back();
        }
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++ ){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> res;
    findSubset(a, res, k, 0);
    if (!ok) {
        cout << "-1";
    }
    ok = false;
}