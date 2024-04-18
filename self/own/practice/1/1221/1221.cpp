#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        int dem = 0;
        int res = 0;
        int n = s.size();
        for (int i = 0;i < n; i++) {
            if (s[i] == 'L') {
                dem++;
            } else {
                dem--;
            }
            if (dem == 0) {
                res++;
            }
        }
        return res;
    }
};
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution h;
        cout << h.balancedStringSplit(s) << endl;
    }
    
    return 0;
}
