#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTree {
    vector<pair<int, int>> tree;
    int n;

    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], -1};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    pair<int, int> merge(pair<int, int> left, pair<int, int> right) {
        vector<int> values = {left.first, left.second, right.first, right.second};
        sort(values.rbegin(), values.rend());
        return {values[0], values[1]};
    }

    pair<int, int> query(int L, int R, int node, int start, int end) {
        if (R < start || end < L) {
            return {-1, -1};
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        pair<int, int> left = query(L, R, 2 * node + 1, start, mid);
        pair<int, int> right = query(L, R, 2 * node + 2, mid + 1, end);
        return merge(left, right);
    }

    pair<int, int> query(int L, int R) {
        return query(L, R, 0, 0, n - 1);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    SegmentTree segTree(P);
    long long totalSum = 0;

    for (int L = 0; L < N; ++L) {
        for (int R = L + 1; R < N; ++R) {
            pair<int, int> result = segTree.query(L, R);
            totalSum += result.second;
        }
    }

    cout << totalSum << endl;
    return 0;
}
