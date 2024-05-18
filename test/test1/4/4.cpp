#include <bits/stdc++.h>
using namespace std;
/*
Cho mảng các số A[] gồm N phần tử. Hãy kiểm tra xem mảng A[] có tồn tại một dãy K phần tử liên tiếp có tổng đúng bằng S hay không? Đưa ra giá trị Yes nếu mảng A[] thỏa mãn yêu cầu bài toán, ngược lại đưa ra “No”.

Input:

Dòng đầu tiên đưa vào số T là số lượng bộ test (T≤100).
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 02 dòng: dòng đầu tiên đưa vào N, K, S; dòng kế tiếp là N phần tử của mảng A[].
N, K, S, A[i] thỏa mãn ràng buộc: 1 ≤ K, S, N, A[i]≤ 105.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
*/
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
	int n, k, s;
	cin >> n >> k >> s;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int x = k;
		int j = i + 1;
		int sum = 0;
		while (x--) {
			sum += a[j];
			j++;
		}
		if (sum == s) {
			cout << "Yes";
			return;
		}
	}
	cout << "No";
}