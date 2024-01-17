#include <iostream>
#include <vector>
using namespace std;
void testCase();
int main() {
    // Write your code here
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
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(a[i], a[minIndex]);
        }
        res.push_back(a);
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}