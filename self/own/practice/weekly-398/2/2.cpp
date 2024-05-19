#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> res;
        for (auto &q : queries) {
            bool ok = true;
            for (int i = q[0]; i < q[1]; i++) {
                if (nums[i] % 2 == nums[i + 1] % 2) {
                   ok = false;
                    break;
                }
            }
            res.push_back(ok);
        }
        return res;
    }
};
void testCase() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution h;
    vector<bool> res = h.isArraySpecial(nums, queries);
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
