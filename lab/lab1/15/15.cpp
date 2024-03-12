#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
void testCase() ;
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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a.push_back(make_pair(i, abs(x - b[i])));
    }
    sort(a.begin(), a.end(), cmp);
    for (auto x : a) {
        cout << b[x.first] << " ";
    }
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}