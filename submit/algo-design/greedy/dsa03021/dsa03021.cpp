#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(N);
    B[0] = 1;
    for (int i = 1; i < N; i++) {
        B[i] = max(B[i-1], (A[i-1] + A[i] - 1) / A[i]);
    }
    int sum = accumulate(B.begin(), B.end(), 0);
    cout << sum << endl;
    return 0;
}