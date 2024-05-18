#include <bits/stdc++.h>
using namespace std;
/*
Cho mảng A[] gồm n số nguyên không âm. Ta gọi phần tử A[i] là hợp lệ nếu A[i]≠0 ngược lại là không hợp lệ. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng theo nguyên tắc nếu số A[i+1] (i=0,..,n-2) là số hợp lệ và A[i] = A[i+1] thì nhân đôi A[i] và thiết lập A[i+1] = 0. Sau khi thay đổi, hãy di chuyển các số không hợp lệ vào cuối mảng. Các số hợp lệ phải bảo toàn quan hệ trước sau. Ví dụ với mảng A[] = {2, 2, 0, 4, 0, 8 }thực hiện theo nguyên tắc trên ta được kết quả A[] = { 4, 4, 8, 0, 0, 0}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤105; 1≤ A[i] ≤105;
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] != 0 && a[i] == a[i + 1]) {
			a[i] *= 2;
			a[i + 1] = 0;
		}
	}
	vector<int> b, c;
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			b.push_back(a[i]);
		} else {
			c.push_back(a[i]);
		}
	} 
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << " ";
	}
} 