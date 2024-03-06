#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> res;
void testCase();
void findCombinations(vector<int> a, vector<int> &combination, int start);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void findCombinations(vector<int> a, vector<int> &combination, int start) {
    for (int i = start; i < a.size(); i++) {
        combination.push_back(a[i]);
        int sum = 0;
        for (int i = 0; i < combination.size(); i++) {
            sum += combination[i];
        }
        if (sum % 2 == 1) {
            res.push_back(combination);
        }
        findCombinations(a, combination, i + 1);
        combination.pop_back();
    }
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    vector<int> combination;
    res.clear();
    findCombinations(a, combination, 0);
    sort(res.begin(), res.end());
    for (auto x : res) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
}