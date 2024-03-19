#include <bits/stdc++.h>
using namespace std;
void testCase();
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int, int> unionMap, intersection;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        unionMap[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (unionMap[b[i]] >= 1) {
            intersection[b[i]]++;
        }
        unionMap[b[i]]++;
    }
    for (auto x : unionMap) {
        cout << x.first << " ";
    }
    cout << endl;
    for (auto x : intersection) {
        cout << x.first << " ";
    }
}