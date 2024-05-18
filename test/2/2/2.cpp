/*
Cho dãy số A[] có N phần tử. Với mỗi vị trí thứ i trong dãy, hãy tính độ dài của đoạn liên tiếp tính từ i trở về phía trước mà các giá trị đều nhỏ hơn hoặc bằng A[i].

Input: Dòng đầu ghi số bộ test (không quá 10). Mỗi test có 2 dòng.

Dòng đầu tiên gồm 1 số nguyên N (1 ≤ N ≤ 105).
Dòng tiếp theo gồm N số nguyên A1, A2, …, AN (1 ≤ A[i] ≤ 106).
Output

Với mỗi bộ test, in ra dãy kết quả trên một dòng.

*/
#include <bits/stdc++.h>
using namespace std;

void testCase() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res[n];
	res[0] = 1;
	for (int i = 1; i < n; i++) {
		int len = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] <= a[i]) {
				len++;
			} else {
				break;
			}
		}
		res[i] = len;
	}
	for (int i = 0; i < n; i++ ){
		cout << res[i] << " ";
	}
}
void testCase2() {
	stack<long long> st;
	long long n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long res[n];
	res[0] = 1;
	st.push(a[0]);
	stack<long long> temp;
	for (int i = 1; i < n; i++ ){
		long long len;
		if (a[i] <= st.top()) {
			st.push(a[i]);
			res[i] = 1;
		} else {
			long long dem = 1;
			temp = st;
			while (!temp.empty() && a[i] > temp.top()) {
				temp.pop();
				dem++;
			}
			st.push(a[i]);
			res[i] = dem;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
}
void testCase3() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        res[i] = (st.empty() ? i + 1 : i - st.top());
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
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
	// cout << t << endl;
	while (t--) {
		testCase3();
		cout << endl;
	}
	return 0;
}