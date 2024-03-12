#include <iostream>
#include <map>
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
    int a[n], b[m];
    map<int, int> mp, intersection;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (mp[b[i]] >= 1) {
            intersection[b[i]]++;
        }
        mp[b[i]]++;

    }
    for (auto x : mp) {
        cout << x.first << " ";
    }
    cout << endl;
    for (auto x : intersection) {
        cout << x.first << " ";
    }
}