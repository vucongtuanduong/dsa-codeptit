#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> b;
void testCase();
void Try(int i);
void print(vector<int> a);
int main() {
    // Write your code here
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void print(vector<int> a) {
    cout << "[";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) {
            cout << " ";
        }
    }
    cout << "]";
    cout << endl;
}
void Try(int i) {
    print(a);
    if (i == 1) {
        return;
    }
    for (int j = 0; j < i - 1; j++) {
        b.push_back(a[j] + a[j + 1]);
    }
    a = b;
    a.resize(i - 1);
    b.clear();
    Try(i - 1);
}
void testCase() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Try(n);
}