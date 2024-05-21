#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    void Try(int i) {
        for (int j = 0; j <= 1; j++) {
            temp[i] = j;
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        res.clear();
        temp.resize(n);
        Try(0);    
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
