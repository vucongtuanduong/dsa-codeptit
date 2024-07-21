#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    vector<long long> dp(N, LLONG_MAX);
    dp[0] = 0;
    
    deque<int> dq;
    dq.push_back(0);
    
    for (int i = 1; i < N; ++i) {
        while (!dq.empty() && dq.front() < i - 1) {
            dq.pop_front();
        }
        
        long long cost = (H[i] - H[dq.front()]) * (H[i] - H[dq.front()]) + C;
        dp[i] = dp[dq.front()] + cost;
        
        while (!dq.empty() && dp[dq.back()] >= dp[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
    }
    
    cout << dp[N-1] << endl;
    
    return 0;
}
