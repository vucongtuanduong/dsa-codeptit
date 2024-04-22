#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[100];
bool check;
int res = 0;
void init();
void Try(int s, int lim, int cnt);
int main() {
    // Write your code here
    init();
    Try(0, s, 0);
    if (!check) {
        cout << "-1";
        
    } else {
        cout << res;
    }
    return 0;
}
void init() {
    res = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    
    check = false;
}
void Try(int i, int sum, int cnt) {
    if (check) {
        return;
    }
    if (sum == 0) {
        check = true;
        res = cnt;
        return;
    }
    if (sum >= a[i]) {
        Try(i + 1, sum - a[i], cnt + 1);
    }
}