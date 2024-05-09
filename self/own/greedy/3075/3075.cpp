#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long res = 0;
        for (int i = 0; i < k; i++){
            long long temp = happiness[i] - i;
            if (temp < 0) {
                temp = 0;
            }
            res += temp;
        }
        return res;
    }
};
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> happiness(n);
    for (int i = 0; i < n; i++) {
        cin >> happiness[i];
    }
    Solution h;
    cout << h.maximumHappinessSum(happiness, k);
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
