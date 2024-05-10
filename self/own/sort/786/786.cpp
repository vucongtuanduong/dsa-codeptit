#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int>b) {
        double x = (1.0 * a.first) / a.second;
        double y  = (1.0 * b.first) / b.second;
        return x < y; 
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> res;
        vector<pair<int, int>> total;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                total.push_back({arr[i], arr[j]});
            }
        }
        sort(total.begin(), total.end(), cmp);
        res.push_back(total[k - 1].first);
        res.push_back(total[k - 1].second);
        return res;
    }
};
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution h;
    vector<int>res = h.kthSmallestPrimeFraction(arr, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
int main() {
    // Write your code here 
    int  t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
