#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int> a;
vector<int> res;
bool ok ;
void Try(int sum, int start) {
    if (sum == 0) {
        cout << "[";
        ok = true;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] ;
            if (i != res.size() - 1) {
                cout << " ";
            }
        }
        cout << "]";
    } else {
        for (int j = start; j < n; j++) {
            if (a[j] <= sum) {
                res.push_back(a[j]);
                Try(sum - a[j], j);
                res.pop_back();
            }
        }
    }

}
void testCase() {
    cin >> n >> x;
    ok = false;
    res.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Try(x, 0);
    if (!ok) {
        cout << "-1";
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
