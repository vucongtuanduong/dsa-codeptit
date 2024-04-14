#include <bits/stdc++.h>
using namespace std;
int n, k;
long long res;
int x[101];
bool used[101];
vector<string> s;
void testCase();
void Try(int i);
void result();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void result() {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 1; j <= k; j++) {
            temp += s[i][x[j] - 1];
        }
        v.push_back(stoi(temp));

    }
    sort(v.begin(), v.end());
    res = min(res, (long long)(v[n - 1] - v[0]));
}
void Try(int i) {
    for (int j = 1; j <= k; j++) {
        if (!used[j]) {
            x[i] = j;
            used[j] = true;
            if (i == k) {
                result();
            } else {
                Try(i + 1);
            }
            used[j] = false;
        }
    }
}
void testCase() {
    cin >> n >> k;
    s.resize(n);
    for (int i= 0; i < n; i++) {
        cin >> s[i];
    }
    res = INT_MAX;
    for (int i = 1; i <= k; i++) {
        used[i] = false;
    }
    Try(1);
    cout << res << endl;
}