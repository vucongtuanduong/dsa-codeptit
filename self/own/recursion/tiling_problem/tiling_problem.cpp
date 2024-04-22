#include <bits/stdc++.h>
using namespace std;
int numWays(int n, int m) {
    if (n < m) {
        return 1;
    } 
    return numWays(n - 1, m) + numWays(n - 4, m);
}
int main() {
    // Write your code here
    int n, m;
    cin >> n >> m;
    cout << numWays(n, m);
    return 0;
}
