#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
    }
};
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat;
    mat.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    Solution h;
    vector<int> res = h.rowAndMaximumOnes(mat);
    for (auto x : res) {
        cout << x << " ";
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
