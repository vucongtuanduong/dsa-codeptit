#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) {
                cnt++;
            }
        }
        if (cnt == 0) {
            return 0;
        }
        // vector<int> res;
        int ans = 0;
        for (auto x : mp) {
            if (x.second == 2) {
                ans ^= x.first;
            }
        }
        return ans;

    }
};
void testCase() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution h;
    cout << h.duplicateNumbersXOR(nums);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
