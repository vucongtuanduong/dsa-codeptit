#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void testCase();
void findCombinations(vector<int> a, int x, vector<int> &combination, int start) {
    if (x == 0) {
        res.push_back(combination);
    }
    for (int i = start; i < a.size(); i++) {
        if (a[i] <= x) {
            combination.push_back(a[i]);
            findCombinations(a, x - a[i], combination, i);
            combination.pop_back();

        }
    }
}
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i= 0; i < n; i++) {
        cin >> a[i];

    }
    res.clear();
    vector<int> combination;
    bool ok = false;
    findCombinations(a, x, combination, 0);
    if (res.size() == 0) {
        cout << "-1";
        return;
    } else {
        cout << res.size()  << " ";
        for (auto x : res) {
            cout << "{";
            for (int i = 0; i < x.size(); i++) {
                cout << x[i] ;
                if (i != x.size() - 1) {
                    cout << " ";
                }
            }
            cout << "} ";
        }
    }

}