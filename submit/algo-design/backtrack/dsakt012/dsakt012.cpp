#include <bits/stdc++.h>
using namespace std;
int money[100];

bool check = false;
int res;
int n, s;
void testCase();
void Try(int sum_money, int lim, int cnt);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    testCase();
    return 0;
}
void Try(int sum_money, int lim, int cnt) {
    if (check) return;
    if (sum_money < 0) return;
    if (sum_money == 0) {
        check = 1;
        res = cnt;
        return;
    }
    for (int j = lim; j >= 0; j--) {
        Try(sum_money - money[j], j - 1, cnt + 1);
    }
}
void testCase() {
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> money[i];
    sort(money, money + n);

    check = false;
    Try(s, n - 1, 0);

    if (check)
        cout << res << endl;
    else cout << -1 << endl;
}