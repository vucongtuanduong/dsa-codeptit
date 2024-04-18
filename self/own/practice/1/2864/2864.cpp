#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int count1s = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count1s++;
            }
        }
        int count0s = n - count1s;
        string res = "";
        for (int i = 0; i < count1s - 1; i++) {
            res += "1";
        }
        for (int i = 0; i < count0s; i++ ){
            res += "0";
        }
        res += "1";
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
        cout << h.maximumOddBinaryNumber(s) << endl;
    }
    return 0;
}
