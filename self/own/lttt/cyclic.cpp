#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <cstdlib>
#include <bitset>
#include <numeric>
#include <unordered_set>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int x[100] = { 0 };
vector<int> v;
vector<int> ans;

bool chiahet(vector<int> v, vector<int> u, int n) {
	ans.clear();
	while (true) {
		int d = v[0] - u[0];
		ans.push_back(d);

		vector<int> c;
		for (int i = 0; i < u.size(); i++) {
			c.push_back(u[i] + d);
		}

		int i = 0;
		int j = 0;
		vector<int> res;
		while (i < v.size() && j < c.size()) {
			if (v[i] == c[j]) {
				i++;
				j++;
			}
			else if (v[i] < c[j]) {
				res.push_back(c[j]);
				j++;
			}
			else if (v[i] > c[j]) {
				res.push_back(v[i]);
				i++;
			}
		}
		while (i < v.size()) res.push_back(v[i++]);
		while (j < c.size()) res.push_back(c[j++]);

		sort(res.begin(), res.end(), greater<int>());
		v = res;
		if (v.empty()) return true;
		if (!v.empty() && v[0] < u[0]) return false;
	}
}

void kiemtra(int n) {
	
	vector<int> u;
	u.push_back(n + 1);
	for (int i = n; i >= 1; i--) {
		if (x[i]) u.push_back(i);
	}
	u.push_back(0);
	while (!v.empty() && chiahet(v, u, n)) {
		v = ans;
		for (auto x : u) {
			if (x == 0) cout << 1;
			else
				if (x == 1) cout << "x + ";
				else
					cout << "x^" << x << " + ";
		}
		cout << endl;
	}
}

void sinh_nhi_phan(int i, int n) {
	if (v.empty()) return;
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) kiemtra(n);
		else sinh_nhi_phan(i + 1, n);
	}
}
int main() {
	// int n;
	// cin >> n;
	for (int i = 6; i <= 15; i++) {
		int n = i;
		cout << "i: " << i << endl;
		v.push_back(n);
		v.push_back(0);

		for (int i = 1; i <= n - 1; i++) {
			if (v[0] == 0) break;
			if (i >= 2) sinh_nhi_phan(1, i - 1);
			else if (i == 1) kiemtra(0);
		}
		cout << endl;
		v.clear();
		ans.clear();
	}
	
	

	//for (auto x : v) cout << x << " - ";

	return 0;
}