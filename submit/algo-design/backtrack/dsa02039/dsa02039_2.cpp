#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> res;
vector<int> a;
void Try(int sum, int maxNum) {
    if (sum == 0) {
        res.push_back(a);
    } else {
        for (int i = min(sum, maxNum); i >= 1; i--) {
            a.push_back(i);
            Try(sum - i, i);
            a.pop_back();
        }
    }
}
void testCase() {
    cin >> n;
    res.clear();
    Try(n, n);
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int x = res.size() - 1; x >= 0; x--) {
        cout << "(";
        for (int i = 0; i < res[x].size(); i++)  {
            cout << res[x][i];
            if (i != res[x].size() - 1) {
                cout << " ";
            }
        }
        cout << ") ";
    }
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--){
        testCase();
        cout << endl;
    }
    return 0;
}
