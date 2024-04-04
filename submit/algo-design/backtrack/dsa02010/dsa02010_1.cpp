#include <bits/stdc++.h>
using namespace std;
int countRes = 0;
vector<int> a;
vector<int>comb;
vector<vector<int>>res;
void testCase();
void Try(int x, int start);
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
void Try(int x, int start) {
    if (x == 0) {
        countRes++;
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            
            if (i != 0) {
                cout << " ";
            }
            cout << comb[i];
            
        }
        cout << "]";
        return;
    }
    for (int i = start; i < a.size(); i++) {
        if (a[i] <= x) {
            comb.push_back(a[i]);
            Try(x - a[i], i);
            comb.pop_back();
        }
    }
}
void testCase() {
    countRes = 0;
    int n, x;
    cin >> n >> x;
    a.resize(n);
    res.clear();
    comb.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    Try(x, 0);
    if (countRes == 0) {
        cout << "-1";
        return;
    }
}