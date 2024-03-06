#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void testCase();
void findSubset(vector<int>a, vector<int> &subset, int start, int k);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }

    return 0;
}
void findSubset(vector<int>a, vector<int> &subset, int start, int k) {
    if (subset.size() == k) {
        res.push_back(subset);
    }
    for (int i = start; i < a.size(); i++) {
        subset.push_back(a[i]);
        findSubset(a, subset, i + 1, k);
        subset.pop_back();
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> subset;
    res.clear();
    sort(a.begin(), a.end());
    findSubset(a, subset, 0, k);
    sort(res.begin(), res.end());
    for (auto x : res) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        } 
        cout << endl;
    }

}