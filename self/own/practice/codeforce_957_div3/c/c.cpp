#include <iostream>
#include <vector>
using namespace std;

void testCase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> res;
    for (int i = n; i >= k; i--) {
        res.push_back(i);
    }

    for (int i = m + 1; i < k; ++i) {
        res.push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
       res.push_back(i);
    }
    for (int x : res) {
        cout << x << " ";
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}