#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j =0 ; j < m; j++) {
            cin >> a[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({0, 0});
    int res = 0;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    visited[0][0] = 0;
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        if (x == n  - 1 && y == m- 1) {
            cout << visited[x][y];
            return;
        }
        int new_x = temp.first + a[x][y];
        int new_y = temp.second + a[x][y];
        
        if (new_x >= 0 && new_x  < n && y >= 0 && y < m &&  visited[new_x][y] == -1)  {
            visited[new_x][y] = visited[x][y] + 1;
            res++;
            q.push({new_x, temp.second});
        }
        if (new_y >= 0 && new_y < m && visited[x][new_y] == -1) {
            visited[x][new_y] = visited[x][y] + 1;
            res++;
            q.push({temp.first, new_y});
        }
    }
    cout << "-1";
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
