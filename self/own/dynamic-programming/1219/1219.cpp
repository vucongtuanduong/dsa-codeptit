#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const vector<int> dx = {0, 0, -1, 1};
    const vector<int> dy = {-1, 1, 0, 0};
public:
    int dfs(vector<vector<int>>&grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0) {
            return 0;
        }
        int res = 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            res = max(res, temp + dfs(grid, new_x, new_y, n, m));

        }
        grid[i][j] = temp;
        return res;

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dfs(grid, i, j, n, m));
            }
        }
        return  res;
        
    }
};
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution h;
    cout << h.getMaximumGold(grid);
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
