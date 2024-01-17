#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
void testCase();
bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
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