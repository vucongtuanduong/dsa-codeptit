#include <bits/stdc++.h>
using namespace std;

int calArea(vector<int> height) {
    stack<int> st;
    int maxArea = 0;
    int n = height.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || height[i] < height[st.top()])) {
            int nowHeight = height[st.top()];
            st.pop();
            int width;
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }
            maxArea = max(maxArea, nowHeight * width);
        }
        st.push(i);
    }
    return maxArea;
}
int largestArea(vector<vector<int>> &a, int n, int m) {
    vector<int> height(m, 0);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        maxArea = max(maxArea, calArea(height));
    }
    return maxArea;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];
    vector<int> hist(M, 0);
    int max_area = 0, min_side = 0, max_side = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 0)
                hist[j] = 0;
            else
                hist[j] += 1;
        }
        int area = largestRectangleArea(hist);
        if (area > max_area) {
            max_area = area;
            max_side = *max_element(hist.begin(), hist.end());
            min_side = max_area / max_side;
        }
    }
    cout << min_side << " " << max_side << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}