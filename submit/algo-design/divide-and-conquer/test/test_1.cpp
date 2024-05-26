#include <bits/stdc++.h>
using namespace std;

bool whoWins(int n) {
    return (n % 4 != 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (whoWins(n) ? "true" : "false") << endl;
    }
    return 0;
}