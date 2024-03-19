#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> min_index(n);
    min_index[0] = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[min_index[i - 1]]) {
            min_index[i] = i;
        } else {
            min_index[i] = min_index[i - 1];
        }
    }
    int j = n - 1;
    int i = min_index[n - 1];
    int max_diff = -1;
    while (j >= 0) {
        if (A[j] > A[i]) {
            max_diff = max(max_diff, j - i);
            j--;
        } else if (i > 0) {
            i = min_index[i - 1];
        } else {
            j--;
        }
    }
    cout << max_diff << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        testCase();
    }
    return 0;
}