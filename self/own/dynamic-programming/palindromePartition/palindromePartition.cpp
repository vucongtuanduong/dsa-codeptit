#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s;
    bool isPalindrome(int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> dp(int i) {
        vector<vector<string>> res;
        for (int j = i; j < s.size(); j++) {
            vector<string> temp;
            if (isPalindrome(i, j)) {
                temp.push_back(s.substr(i, j));
                res.push_back(temp);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        this->s = s;
        return dp(0);
    }
};
int main() {
    // Write your code here
    string s;
    cin >> s;
    Solution h;
    vector<vector<string>> res  = h.partition(s);
    for (auto x : res) {
        for (auto t : x) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}
