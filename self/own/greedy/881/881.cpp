#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        int n =people.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            res++;
        }
        return res;
    }
};
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> people(n);
        for (int i = 0; i < n; i++) {
            cin >> people[i];
        }
        Solution h;
        cout << h.numRescueBoats(people, k) << endl;
    }
    return 0;
}
