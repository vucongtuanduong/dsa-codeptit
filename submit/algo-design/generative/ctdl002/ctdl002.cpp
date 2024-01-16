#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& subset, int start);
void printSubsets(vector<vector<int>>& subsets);

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> subsets;
    vector<int> subset;
    findSubsets(nums, K, subsets, subset, 0);
    printSubsets(subsets);
    cout << subsets.size() << endl;
    return 0;
}

void findSubsets(vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& subset, int start) {
    if (target == 0) {
        result.push_back(subset);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        if (nums[i] > target) continue;
        subset.push_back(nums[i]);
        findSubsets(nums, target - nums[i], result, subset, i + 1);
        subset.pop_back();
    }
}

void printSubsets(vector<vector<int>>& subsets) {
    reverse(subsets.begin(), subsets.end());
    for (const auto& subset : subsets) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
}