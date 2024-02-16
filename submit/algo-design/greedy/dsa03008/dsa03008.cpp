#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
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
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
void testCase() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a, a + n, cmp);
    vector<int> res;
    res.push_back(a[0].first);
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (a[j].first >= a[i].second) {
            res.push_back(a[j].first);
            i = j;
        }
    }
    cout << res.size();
}