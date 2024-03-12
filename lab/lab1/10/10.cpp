#include <iostream>
#include <algorithm>
#include <vector>
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
    // testCase();
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
    for (int i = n - 1; i > 0; i--) {
        bool swapped = false;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        res.push_back(a);
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i + 1<< ": ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}