#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
    unordered_set<int> se;
    // int cnt= 0;
    while (x > 0) {
        
        se.insert(x % 10);
        x/= 10;
    }
    return se.size() <= 2;
}
int main() {
    // Write your code here
    int res = 0;
    for (int i = 1; i <= 999999999; i++) {
        if (check(i)) {
            res++;
            cout << i << " ";
        }
    }
    cout << "\n" << res << endl;
    return 0;
}
