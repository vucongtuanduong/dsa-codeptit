#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void testCase();
bool cmp(pair<int, int> a, pair<int, int> b);
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
    int a[n];
    map<int, int> mp;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++ ){
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto x : mp) {
        res.push_back(x);
    }
    sort(res.begin(), res.end(), cmp);
    for (auto x : res) {
        while (x.second--) {
            cout << x.first << " ";
        }
    }
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}