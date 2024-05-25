#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occurrences;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                occurrences.push_back(i);
            }
        }
        vector<int> result;
        for (int query : queries) {
            if (query - 1 < occurrences.size()) {
                result.push_back(occurrences[query - 1]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
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
    // vector<int> res = occurrencesOfElement(nums)
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