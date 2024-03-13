#include<bits/stdc++.h>
using namespace std;

string isSubarraySum(int N, long long K, vector<long long>& A) {
    long long sum = A[0];
    int start = 0;
    for (int i = 1; i <= N; i++) {
        while (sum > K && start < i-1) {
            sum -= A[start];
            start++;
        }
        if (sum == K) {
            return "YES";
        }
        if (i < N) {
            sum += A[i];
        }
    }
    return "NO";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long K;
        cin >> N >> K;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << isSubarraySum(N, K, A) << endl;
    }
    return 0;
}