#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        int x = num;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        int n = digits.size();
        sort(digits.begin(), digits.end());
        int i = 0;
        int a = 0, b = 0;
        while (i < n) { 
            a = a * 10 + digits[i];
            i++;
            if (i != n) {
                b = b * 10 + digits[i];
                i++;
            }
        }
        // cout << "a: " << a << ", b : " << b << endl; 
        int res = a + b;
        return res;
    }
};
int main() {
    // Write your code here
    int num;
    cin >> num;
    Solution h;
    cout <<  h.minimumSum(num) << endl;
    return 0;
}
