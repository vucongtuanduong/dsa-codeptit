/*
Trong các công ty IT, lập trình viên là một loại nhân sự đặc biệt. Nếu trả mức lương quá thấp, anh ta sẽ không muốn làm việc, năng suất sẽ thấp, thậm chí thỉnh thoảng lại dọa bỏ đi nơi khác. Nếu trả mức lương quá cao thì anh ta lại lười biếng và chẳng muốn làm việc gì cả. Mức lương vừa đủ sẽ khiến động lực làm việc tăng cao và năng suất sẽ là cao nhất.

Giả sử có N lập trình viên, mỗi người có một ngưỡng trả lương từ A[i] đến B[i] gọi là vừa đủ. Nếu lương nhỏ hơn A[i] thì số dòng code đúng mỗi ngày của lập trình viên thứ i sẽ là X, nếu trong đoạn từ A[i] đến B[i] thì số dòng code sẽ là Y, còn nếu lớn hơn B[i] thì số dòng code sẽ là Z. Tất nhiên, Y>X và Y>Z.

Hãy giúp giám đốc công ty chọn ra mức lương nào đó chung cho cả N lập trình viên và tổng số dòng code đúng trong một ngày là lớn nhất có thể.

Input

Dòng 1 ghi 4 số N, X, Y, Z (1 <= N <=20000; 0 <= X,Y,Z <=1000)

N dòng tiếp theo, mỗi dòng ghi hai số A[i] và B[i] (0 <= A[i] <= B[i] <= 109)

Output

Ghi ra số dòng code đúng tối đa có thể đạt được.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void testCase() {
	
	long long n, x, y, z;
	cin >> n >> x >> y >> z;
	pair<int, int> a[n];
	int minn = INT_MAX, maxx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first < minn) {
			minn = a[i].first;
		}
		if (a[i].second > maxx) {
			maxx = a[i].second;
		}
	}
	vector<long long> kq;
	long long sum =0;
	for (int i = minn; i <= maxx; i++ ) {
		for (int j = 0; j < n; j++) {
			if (i < a[j].first) {
				sum += x;
			} else if (i > a[j].second) {
				sum += z;
			} else {
				sum += y;
			}
		}

		kq.push_back(sum);
		sum = 0;
	}
	// int size = kq.size();
	// for (auto x : kq) {
	// 	cout << x << " ";
	// }
	cout << *max_element(kq.begin(), kq.end());

}
void testCase2() {
    ll n, x, y, z, ans = 0;
    cin >> n >> x >> y >> z;
    vector <pair <ll, ll>> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end(), cmp);
    for (ll i = n; i > 1; i--) {
        int cnt = 0;
        for (ll j = i - 1; j > 0; j--) {
            if (v[i].first > v[j].second) cnt++;
        }
        ans = max(ans, (i - cnt) * y + cnt * z + (n - i) * x);
    }
    cout << ans;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	testCase2();
	return 0;
}