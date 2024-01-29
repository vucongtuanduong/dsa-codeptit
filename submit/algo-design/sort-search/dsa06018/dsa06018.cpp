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
    int a[n];
    set<int> se;
    for (int i = 0; i < n; i++) {

        cin >> a[i];
        se.insert(a[i]);
    }
    int count = 0;
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    for (int i = min; i <= max; i++) {
        if (se.count(i) == 0) {
            count++;
        }
    }
    cout << count;
}