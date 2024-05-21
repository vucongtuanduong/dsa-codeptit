#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    int n;
    void result(vector<int> nums) {
        vector<int> kq;
        for (int i = 0; i < n; i++) {
            if (temp[i] == 1) {
                kq.push_back(nums[i]);
            }
        }
        res.push_back(kq);
    }
    void Try(int i, vector<int> nums) {
        for (int j = 0; j <= 1; j++) {
            temp[i] = j;
            if (i == n - 1) {
                result(nums);
            } else {
                Try(i + 1, nums);
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        res.clear();
        temp.resize(n);
        Try(0, nums);    
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
    Solution h;
    vector<vector<int>> res = h.subsets(nums);
    for (auto x : res) {
        for (auto u : x) {
            cout << u << " ";
        }
        cout << endl;
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
