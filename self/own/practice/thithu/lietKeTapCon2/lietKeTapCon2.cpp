#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> input, res;
int a[101];
void init() {
    cin >> n >> k;
    input.resize(n);
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
}
void result() {
    string s = "";
    for (int i = 1; i <= k; i++) {
        s += input[a[i] - 1];
    }
    if (s != "") {
        res.push_back(s);
    }
    
}
void Try(int i) {
    for (int j = a[i - 1] + 1; j <= (n - k + i); j++) {
        a[i] = j;
        if (i == k) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    init();
    Try(1);
    sort(res.begin(), res.end());
    for (auto x : res) {
        cout << x << endl;
    }

}
int main() {
    // Write your code here
    testCase();
    return 0;
}
