#include <bits/stdc++.h>
using namespace std;
void init(int n, vector<int> &a);
void dynamic(vector<int> a);
int main() {
    // Write your code here
    int n;
    cin >> n;
    vector<int> a(n);
    init(n, a);
    dynamic(a);
    return 0;
}
void init(int n, vector<int> &a) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void dynamic(vector<int> a) {
    int n = a.size();
    vector<int> dp(n, 1);//tao mang dp de luu do dai cua day con tang dai nhat tai moi vi tri thu i

    //duyet qua tung phan tu cua day va cap nhat gia tri tai moi vi tri trong day
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

    }
    cout << *max_element(dp.begin(), dp.end()) << endl;

}