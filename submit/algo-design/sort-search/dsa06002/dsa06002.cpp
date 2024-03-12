#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
void testCase();
bool cmp(pair<int,int> a, pair<int,int> b);
void testCase2();
bool cmp2(pair<int, int> a, pair<int, int> b);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase2();
        cout << endl;
    }
    return 0;
}
bool cmp2(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void testCase2() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[i] = abs(x- a[i]);
    }
    vector<pair<int, int>> res;
    for (auto x : mp) {
        res.push_back(x);
    }
    sort(res.begin(), res.end(), cmp2);
    for (int i = 0; i < res.size(); i++) {
        cout << a[res[i].first] << " ";
    }

}
bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void testCase() {
    int n, x;
    cin >> n >> x;
    int a[n];
    int b[n];
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] = abs(x - b[i]);
        v.push_back(make_pair(i, a[i]));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << b[v[i].first] << " ";
    }
}
