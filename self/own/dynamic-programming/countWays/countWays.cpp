#include <bits/stdc++.h>
using namespace std;
int dp(int index, int n, bool previous) {
    //base case 
    if (index == n + 1) {
        return 1;
    }
    int res = 0;
    //either place 0 here
    res += dp(index + 1, n, false);

    //or place 1 here
    if (previous == false) {
        res += dp(index + 1, n, true);
    }
    return res;
}
int main() {
    // Write your code here
    for (int i = 1; i <= 10; i++ ){
        cout << dp(1, i, false) << endl;
    }
    return 0;
}
