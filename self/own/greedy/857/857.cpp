#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double totalCost = INT_MAX;
        double currentTotalQuality = 0;
        vector<pair<double, int>> wageToQualityRatio;
        for (int i = 0; i < n; i++) {
            wageToQualityRatio.push_back({(1.0 * wage[i]) / (1.0 * quality[i]), quality[i]});
        }
        sort(wageToQualityRatio.begin(), wageToQualityRatio.end());
        priority_queue<int> highestQualityWorkers;
        for (int i = 0; i < n; i++) {
            highestQualityWorkers.push(wageToQualityRatio[i].second);
            currentTotalQuality += wageToQualityRatio[i].second;
            if (highestQualityWorkers.size() > k) {
                currentTotalQuality -= highestQualityWorkers.top();
                highestQualityWorkers.pop();
            }
            if (highestQualityWorkers.size() == k) {
                totalCost = min(totalCost, currentTotalQuality * wageToQualityRatio[i].first);
            }
        }
        return totalCost;
    }
};
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> quality(n), wage(n);
    for (int i = 0; i < n; i++) {
        cin >> quality[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> wage[i];
    }
    Solution h;
    cout << h.mincostToHireWorkers(quality, wage, k);
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
