#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2001;
vector<vector<int>> res;
vector<bool> prime(SIZE, false);
void testCase();
void init();
void findSubset(vector<int>a, vector<int> &combination, int start);
int main() {
    // Write your code here
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
    }
    return 0;
}
void findSubset(vector<int>a, vector<int> &combination, int start){ 
    for (int i = start; i < a.size(); i++) {
        combination.push_back(a[i]);
        int sum = 0;
        for (int i = 0; i < combination.size(); i++) {
            sum += combination[i];
        }
        if (prime[sum] == false) {
            res.push_back(combination);
        }
        findSubset(a, combination, i + 1);
        combination.pop_back();
    }
}
void init() {
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i * i < SIZE; i++) {
        if (prime[i] == false) {
            for (int j = i * i; j < SIZE; j += i) {
                prime[j] = true;
            }
        }
    }
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> subset;
    for (int i= 0; i < n; i++) {
        cin >> a[i];
    }
    res.clear();
    sort(a.begin(), a.end(), greater<int>());
    findSubset(a, subset, 0);
    sort(res.begin(), res.end());
    for (auto x : res) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
}