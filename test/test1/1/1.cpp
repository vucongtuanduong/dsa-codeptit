#include <bits/stdc++.h>
using namespace std;
void testCase();
int main () {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while (t--) {
		testCase();
		cout << endl;
	}
}
void testCase() {
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> se;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		se.insert(a[i]);
	}
	int max = *max_element(a.begin(), a.end());
	int min = *min_element(a.begin(), a.end());
	int count = 0;
	for (int i = min; i <= max; i++) {
		if (se.count(i) != 1) {
			count++;
		}
	}
	cout << count;
}