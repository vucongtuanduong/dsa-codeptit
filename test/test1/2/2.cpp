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
	map<int, int> mp;
	vector<long long> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		string temp = to_string(b[i]);
		for (int i = 0; i < temp.size(); i++) {
			mp[temp[i] - '0']++;
		}
	}

	vector<int> a;
	for (auto x : mp) {
		if (x.first % 2 == 1) {
			a.push_back(x.first);
		}
		
	}
	if (a.size() == 0) {
		cout << "-1";
		return;
	} else {
		sort(a.begin(), a.end(), greater<int>());
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
	}

}