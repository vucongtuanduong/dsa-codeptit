#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int res = INT_MIN;
        int n = energy.size();
        for (int x = 0; x < n; x++) {
            int i = x;
            int sum = 0;
            while (i < n) {
                sum += energy[i];
                i += k;
            }
            res = max(res, sum);
        }
        return res;
    }
};
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    Solution h;
    cout << h.maximumEnergy(energy, k);
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
