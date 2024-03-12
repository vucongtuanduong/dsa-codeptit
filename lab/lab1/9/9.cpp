#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void testCase();
int main() {
    // Write your code here
    // int t;
    // cin >> t;
    // while (t--) {
    //     testCase();
    //     cout << endl;
    // }
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    res.push_back(a);
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i;
        for (; j > 0 && a[j - 1] > key; j--) {
            a[j] = a[j - 1];
        }
        a[j] = key;
        res.push_back(a);
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}