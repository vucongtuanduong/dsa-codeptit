#include <bits/stdc++.h>
using namespace std;
vector<int> memo;
int rodCutting(int n, int *prices) {
    if (n == 0) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, prices[i] + rodCutting(n - i, prices));
    }
    return memo[n] = res;
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    int prices[n + 1];
    memo.resize(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
    cout << rodCutting(n, prices) << endl;
    return 0;
}
