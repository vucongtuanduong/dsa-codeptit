#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string compressedString(string word) {
        map<char, int> mp;
        vector<char> a;
        vector<pair<char,int>> input;
        mp[word[0]]++;
        int n = word.size();
        for (int i = 1; i < n; i++) {
            if (mp[word[i]] == 0) {
                input.push_back({word[i - 1], mp[word[i - 1]]});
                mp.clear();
            }
            mp[word[i]]++;
        }
        if (mp[word[n - 1]] > 0) {
            input.push_back({word[n - 1], mp[word[n - 1]]});
        }
        string res = "";
        for (auto x : input) {
            int cnt = x.second / 9 + 1;
            while (cnt--) {
                if (x.second > 9) {
                    res += "9";
                    x.second -= 9;
                    res += string(1, x.first);
                } else if (x.second != 0){
                    res += to_string(x.second);
                    x.second = 0;
                    res += string(1, x.first);
                }  
            } 
        }
        return res;
    }
};
void testCase() {
    string word;
    cin >> word;
    Solution h;
    cout << h.compressedString(word);
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
