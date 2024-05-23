#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int n, res;
    int m;
    vector<int> a;
public:
    bool isvalid(int x) {
        for (int i = 0; i < a.size(); i++) {
            if (abs(a[i] - x) == m) {
                return false;
            }
        }
        return true;
    }
    void Try(vector<int> nums, int i) {
        if (i == n) {
            res++;
            return;
        }
        Try(nums, i + 1);
        if (isvalid(nums[i])) {
            a.push_back(nums[i]);
            Try(nums, i + 1);
            a.pop_back();
            
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        m = k;
        res = 0;
        Try(nums, 0);
        return res - 1;
    }
};
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution h;
    cout << h.beautifulSubsets(a, k);
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
