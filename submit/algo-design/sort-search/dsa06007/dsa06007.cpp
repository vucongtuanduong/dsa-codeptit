#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void testCase();
void testCase2();
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
void testCase2() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> b = a;
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (a[i] == b[i]) i++;
    while (a[j] == b[j] && j > i) j--;
    cout << i + 1 << " " << j + 1;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n-1;
    while (a[l + 1] >= a[l] && l < n - 1) {
        l++;
    }
    if (l == n - 1) {
        cout << "The array is already sorted";
        return;
    }
    while (a[r - 1] <= a[r] && r > 0) {
        r--;
    }
    
    int max = *max_element(a + l, a + r + 1);
    int min = *min_element(a + l, a + r + 1);
    while (l > 0 && a[l - 1] > min) {
        l--;
    }
    while (r < n -1 && a[r + 1] < max) {
        r++;
    }
    cout << l + 1 << " " << r + 1 ;
}