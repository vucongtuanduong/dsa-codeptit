#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;
        int n = colors.size();
        for (int i = 0; i < n; ++i) {
            bool isValid = true;
            for (int j = 1; j < k; ++j) {
                if (colors[(i + j - 1) % n] == colors[(i + j) % n]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> colors1 = {0, 1, 0, 1, 0};
    int k1 = 3;
    cout << "Example 1: " << solution.numberOfAlternatingGroups(colors1, k1) << endl;

    vector<int> colors2 = {0, 1, 0, 0, 1, 0, 1};
    int k2 = 6;
    cout << "Example 2: " << solution.numberOfAlternatingGroups(colors2, k2) << endl;

    vector<int> colors3 = {1, 1, 0, 1};
    int k3 = 4;
    cout << "Example 3: " << solution.numberOfAlternatingGroups(colors3, k3) << endl;

    return 0;
}