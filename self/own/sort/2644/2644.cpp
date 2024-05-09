#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        pair<int, int> res;
        res.first = INT_MIN;
        res.second = INT_MAX;
        for (int i = 0; i < divisors.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++){
                
                if (nums[j] % divisors[i] == 0) {
                    cnt++;
                    // cout << "nums[j]: " << nums[j] << ", divisors[i]: " << divisors[i] << endl;
                }
            }
            if (cnt > res.first) {
                res.first = cnt;
                res.second = divisors[i];
                
                
            } else if (cnt == res.first) {
                res.first = cnt;
                if (divisors[i] < res.second) {
                    res.second = divisors[i];
                }
            }
        }
        return res.second;
    }
    
};
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), divisors(m);
    for(int i = 0; i < n; i++) {
        cin >> nums[i] ;
    }
    for (int i = 0; i < m; i++) {
        cin >> divisors[i];
    }
    Solution h;
    cout << h.maxDivScore(nums, divisors);
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
