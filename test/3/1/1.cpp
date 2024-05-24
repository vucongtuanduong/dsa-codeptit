#include <bits/stdc++.h>
using namespace std;
/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
  Output:

Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in đáp án theo thứ tự tăng dần.
  Ví dụ:

Input

Output

2

2

3

6

6 8 66 68 86 88

14

6 8 66 68 86 88 666 668 686 688 866 868 886 888


*/
void testCase() {
	int n;
	cin >> n;
	queue<string> q;
	vector<string> res;
	q.push("6");
	q.push("8");
	while (!q.empty()) {
		string s = q.front();
		q.pop();
		if (s.size() < n) {
			q.push(s + "6");
			q.push(s + "8");
		}
		res.push_back(s);
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while (t--) {
		testCase();
		cout << endl;
	}
}