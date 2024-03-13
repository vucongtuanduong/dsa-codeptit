#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubarray(int N, vector<int>& A) {
    vector<int> inc(N, 1), dec(N, 1);
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i-1]) {
            inc[i] = inc[i-1] + 1;
        }
    }
    for (int i = N-2; i >= 0; i--) {
        if (A[i] > A[i+1]) {
            dec[i] = dec[i+1] + 1;
        }
    }
    int max_len = 0;
    for (int i = 0; i < N; i++) {
        max_len = max(max_len, inc[i] + dec[i] - 1);
    }
    return max_len;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << longestBitonicSubarray(N, A) << endl;
    }
    return 0;
}