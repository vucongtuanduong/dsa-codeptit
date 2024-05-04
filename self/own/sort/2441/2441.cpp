#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] > 0) {
                return -1;
            }
            if (abs(nums[left]) == nums[right]) {
                return nums[right];
            } else if (abs(nums[left]) > nums[right]) {
                left++;
            } else if (abs(nums[left])  < nums[right]) {
                right--;
            } 

        }
        return -1;
    }
};
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution h;
        cout << h.findMaxK(nums) << endl;
    }
    return 0;
}
