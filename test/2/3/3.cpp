/*
Cho dãy số S gồm N số tự nhiên khác nhau, biết rằng : 1 ≤ N ≤ 6. Hãy xác định xem có bao nhiêu tập con của dãy S (bao gồm cả tập rỗng) có tổng nằm ngoài khoảng A và B (-100,000 ≤ A ≤ B ≤ 100,000).
Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100).
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N, A và B; dòng tiếp theo là n số S[i] ; các số được viết cách nhau một vài khoảng trống.
Output:

Đưa ra kết quả mỗi test theo từng dòng
*/
#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> x;
vector<int> y;
int res;
void result() {
	int sum = 0;
	for (int i = 0; i < n; i++ ) {
		// cout << y[i] << " ";
		if (y[i] == 1) {
			sum += x[i];
		}
	}
	// cout << ", sum : " << sum;
	// cout << endl;
	if (sum < a || sum > b) {
		res++;
	}
}
void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		y[i] = j;
		if (i == n - 1) {
			result();
		} else {
			Try(i + 1);
		}
	}
}
void testCase() {
	
	cin >> n >> a >> b;
	res = 0;
	x.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	y.resize(n);
	Try(0);
	cout << res;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	// cout << t << endl;
	while (t--) {
		testCase();
		cout << endl;
	}
	return 0;
}