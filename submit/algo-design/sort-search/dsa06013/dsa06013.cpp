#include <iostream>
#include <map>
using namespace std;
void testCase() {
    int n, x;
    cin >> n >> x;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (mp[x] == 0) {
        cout << "-1";
    } else {
        cout << mp[x];
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
