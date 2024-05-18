#include <bits/stdc++.h>
using namespace std;
int n;
string ex;
vector<string> a;
vector<int> x;
vector<bool> used;
void result() {
	for (int i = 0; i < x.size(); i++) {
		cout << a[x[i]] << " ";
	}
	cout << ex << endl;
}
void Try(int i) {
	for (int j = 0; j < n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = true;
			if (i == n - 1) {
				result();
			} else {
				Try(i + 1);
			}
			used[j] = false;
		} 
	}
}
void testCase() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> ex;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == ex) {
			index = i;
		}
	}
	a.erase(a.begin() + index);
	n--;
	sort(a.begin(), a.end());
	x.resize(n);
	used.resize(n, false);
	Try(0);
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	//dung cuoi
	// int t;
	// cin >> t;
	// while (t--) {
	// 	testCase();
	// 	cout << endl;
	// }
	testCase();
	return 0;
}