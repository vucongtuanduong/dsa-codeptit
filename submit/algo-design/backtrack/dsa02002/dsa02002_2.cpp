#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b;
vector<vector<int>> res;
void testCase();
void Try(int i);

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
        cout << endl;
    }
    return 0;
}
void Try(int i) {
    res.push_back(a);
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
    res.clear();
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Try(n);
    reverse(res.begin(), res.end());
    for (auto x : res) {
        cout << "[";
        for(int i = 0; i < x.size(); i++) {
            cout << x[i];
            if (i != x.size() - 1)  {
                cout << " ";
            } else {
                cout << "]";
            }
            
        }
        cout << " ";
    }
}