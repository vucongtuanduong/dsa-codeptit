#include <bits/stdc++.h>
using namespace std;
/*

Cho một biểu thức toán học với các dấu ngoặc đơn, các toán hạng và các toán tử.

Với mỗi cặp dấu ngoặc đúng, hãy thay thế dấu mở ngoặc ( thành số 0 và dấu đóng ngoặc thành số 1.

Với các vị trí dấu ngoặc không đúng thì thay thế bằng số -1

Ví dụ biểu thức  ((a+b)- (c+d) thì sẽ được thay thế thành -10a+b1-0c+d1

Input

Dòng đầu ghi số bộ test.

Mỗi bộ test sẽ viết trên một dòng biểu thức có độ dài không quá 1000.

Output

Với mỗi bộ test, viết trên một dòng xâu ký tự sau khi đã thay thế dấu ngoặc.

Ví dụ

Input

Output

3

((a)

(a))

(((abc))((d)))))

-10a1

0a1-1

000abc1100d111-1-1
*/

void testCase2() {
	string s;
	cin >> s;
	int n = s.size();
	
	vector<string> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = string(1, s[i]);
	}
	stack<int> st;
	stack<char> charSt;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			st.push(i);
		} else if (s[i] == ')') {
			if (!st.empty()) {
				res[st.top()] = "0";
				// cout << res[st.top()] << " ";
				res[i] = "1";
				// cout << res[i] << " ";
				st.pop();
			} else {
				res[i] = "-1";
			}
		}
	}
	if (!st.empty()) {
		while (!st.empty()) {
			res[st.top()] = "-1";
			st.pop();
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i];
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
		testCase2();
		cout << endl;
	}
} 