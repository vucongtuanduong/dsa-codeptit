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
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        swap(a[min_index], a[i]);
        res.push_back(a);
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i + 1 << ": ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}