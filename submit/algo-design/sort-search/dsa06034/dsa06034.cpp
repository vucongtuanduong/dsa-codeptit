#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
void testCase();
void testCase2();
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
void testCase2() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++ ){
        cin >> a[i];
        mp[a[i]]++;
    }
    long long  count = 0;
    for (int i = 0; i < n; i++) {
        mp[a[i]]--; // decrement the count of a[i]
        if (mp[k - a[i]] > 0) {
            count += mp[k - a[i]];
        }
        mp[a[i]]++; // increment the count of a[i]
    }
    cout << count / 2;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++ ){
        cin >> a[i];
    }
    sort(a, a + n);
    long long count = 0;
    for (int i = 0; i < n; i++) {
        count += upper_bound(a + i + 1, a + n, k - a[i]) - lower_bound(a + i + 1, a + n, k - a[i]);
    }
    cout << count;
}