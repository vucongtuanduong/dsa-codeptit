#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n);
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({score[i], i});
        }
        sort(a.begin(), a.end(), cmp);
        vector<string> top3 = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        for (int i = 0; i < n; i++) {
            if (i <= 2) {
                res[a[i].second] = top3[i];
            } else {
                res[a[i].second] = to_string(i + 1);
            }
            
        }
        return res;
    }
};
void testCase() {
    int n;
    cin >> n;
    vector<int> score(n);
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    Solution h;
    vector<string> res = h.findRelativeRanks(score);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
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
