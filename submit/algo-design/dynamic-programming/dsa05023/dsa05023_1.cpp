#include <bits/stdc++.h>
using namespace std;
void testCase() {
    string n;
    cin >> n;
    long long res = n[0] - '0';
    for (int i = 1; i < n.size(); i++) {
        long long sum = 0;
        for (int j = i; j >= 0; j--) {
            string temp = n.substr(j, i - j + 1);
            // cout << temp << " ";
            long long num = stoll(temp);
            res += num;
        }
        // res = max(sum, res);
        
        
    }
    cout << res;
}
int main() {
    // Write your code here
    cin.tie(NULL);
    ios_base::sync_with_stdio;
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
