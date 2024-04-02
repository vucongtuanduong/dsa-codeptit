#include <bits/stdc++.h>
using namespace std;
// given n * m grid, find the number of ways to reach the bottom right corner starting from top left. At each cell you can move right or down
int gridWays(int i, int j, int n, int m) {
    if (i == n - 1 && j == m - 1) {
        return 1;
    } 
    if (i >= n || j >= m) {
        return 0;
    }
    int ans = gridWays(i + 1, j, n, m) + gridWays(i,j + 1, n, m) ;
    return ans;
}
int gridWaysMath(int n, int m) {
    int x = n + m - 2;
    int res = 1;
    for (int i = 2; i <= x; i++) {
        res *= i;
    }   
    int tempN = 1, tempM = 1;
    for (int i = 2; i <= n - 1; i++) {
        tempN *= i;
    }
    for (int i = 2; i <= m - 1; i++) {
        tempM *= i;
    }
    res /= (tempM * tempN);
    return res;
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
            }
        }
        cout << gridWays(0, 0, n, m) << endl;
    }
    
    return 0;
}
