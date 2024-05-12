#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char,int> mp1,mp2;
        for (int i = 0; i < s.size(); i++) {
            mp1[s[i]] = i;
            mp2[t[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += abs(mp1[s[i]] - mp2[s[i]]);
        }
        return res;
        
    }
};
void testCase() {
    string s, t;
    cin >> s >> t;
    Solution h;
    cout << h.findPermutationDifference(s, t);

}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
