#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;

	vector<long long> v(n + 1);
	vector<long long> sum(n + 1, 0);

	vector<long long> dp(n + 1, 0);

	for (long long i = 1; i <= n; i++) {
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	for (long long i = 1; i <= k; i++) dp[i] = sum[i];

	for (long long i = k + 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (long long j = i; j >= i - k + 1; j--) {
			dp[i] = max(dp[j - 2] + sum[i] - sum[j] + v[j], dp[i]);
		}
	}

	cout << dp[n] << endl;

	return 0;
}