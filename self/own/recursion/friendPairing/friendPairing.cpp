#include <bits/stdc++.h>
using namespace std;
int countWays(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return countWays(n - 1) + (n - 1) * countWays(n - 2);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << countWays(n) << endl;
    }
    
    return 0;
}
