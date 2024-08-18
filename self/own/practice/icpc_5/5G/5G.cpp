#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateTrappedWater(const vector<int>& heights) {
    int n = heights.size();
    if (n <= 2) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = heights[0];
    rightMax[n - 1] = heights[n - 1];

    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    }

    int trappedWater = 0;
    for (int i = 0; i < n; ++i) {
        trappedWater += max(0, min(leftMax[i], rightMax[i]) - heights[i]);
    }
    return trappedWater;
}


void distributeUnits(vector<int>& heights, int index, int remainingUnits, int& maxWater) {
    if (index == heights.size() || remainingUnits == 0) {
        maxWater = max(maxWater, calculateTrappedWater(heights));
        return;
    }

    for (int i = 0; i <= remainingUnits; ++i) {
        heights[index] += i;
        distributeUnits(heights, index + 1, remainingUnits - i, maxWater);
        heights[index] -= i;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    int maxWater = 0;
    distributeUnits(heights, 0, K, maxWater);

    cout << maxWater << endl;
    return 0;
}