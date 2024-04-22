#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[N], n;
vector<vector<int>> memo;
//whether sum is possible from subset of
//a [.. index]
int subsetSum(int index, int sum) {
    if (index == -1 ) {
        return (sum == 0);
    }
    if (memo[index][sum] != -1) {
        return memo[index][sum];
    }
    bool ans = false;
    //include a[index] in sum
    if (sum >= a[index]) {
        ans |= subsetSum(index - 1, sum - a[index]);
    }

    //exclude 
    ans |= subsetSum(index - 1, sum);
    return memo[index][sum] = ans;
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        int sum;
        cin >> sum >> n;
        memo.resize(n, vector<int> (sum + 1, -1));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << subsetSum(n - 1, sum) << endl;
    }
    
    return 0;
}
