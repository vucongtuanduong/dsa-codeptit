#include <bits/stdc++.h>
using namespace std;
/*
given an array of coin denominations, and ingeger M representing target money, find the min coins required to make the change

*/
//bottom-up approach
int minChange(int money, int *coin, int n) {
    vector<int> dp(money + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= money; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i - coin[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    return dp[money];
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    int coin[n];
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    int money;
    cin >> money;
    cout << minChange(money, coin, n) << endl;
    return 0;
}
