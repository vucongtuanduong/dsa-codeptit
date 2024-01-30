#include <iostream>
#include <algorithm>
#include <set>
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
    int n;
    cin >> n;
    long long a[n];
    set<long long> se;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] * a[i];
        se.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (se.count(a[i] + a[j]) >= 1) {
                cout << "YES";
                return;
            } 
        }
    }
    cout << "NO";
    return;
}