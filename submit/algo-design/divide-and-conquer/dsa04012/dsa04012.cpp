#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<int> P(M), Q(N);
        for (int i = 0; i < M; i++) {
            cin >> P[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> Q[i];
        }
        vector<int> R(M + N - 1, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                R[i + j] += P[i] * Q[j];
            }
        }
        for (int i = 0; i < M + N - 1; i++) {
            cout << R[i] << " ";
        }
        cout << endl;
    }
    return 0;
}