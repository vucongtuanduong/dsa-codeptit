#include <bits/stdc++.h>
using namespace std;

void genNums(set<long long>& nums, long long cur, int d1, int d2, int len, long long N) {
    if (cur > N) return;
    if (len > 0) {
        nums.insert(cur);
        cout << cur << endl;
    }
    if (len == 10) return;
    genNums(nums, cur * 10 + d1, d1, d2, len + 1, N);
    if (d1 != d2) genNums(nums, cur * 10 + d2, d1, d2, len + 1, N);
}

int main() {
    long long N;
    cin >> N;
    set<long long> nums;

    for (int i = 1; i <= 9; ++i) {
        nums.insert(i);
    }

    for (int d1 = 1; d1 <= 9; ++d1) {
        for (int d2 = 0; d2 <= 9; ++d2) {
            if (d1 != d2) {
                genNums(nums, d1, d1, d2, 1, N);
            }
        }
    }

    int count = 0;
    for (auto num : nums) {
        if (num <= N) count++;
    }

    cout << count << endl;
    return 0;
}