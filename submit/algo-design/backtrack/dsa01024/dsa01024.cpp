#include <iostream>
#include <map>
#include <vector>
using namespace std;
void testCase();
void Try(int *a, int n, int k, vector<string> v, int i);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    map<string,int> mp;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s]++;
    }
    vector<string> v;
    for (auto x : mp) {
        v.push_back(x.first);
    }
    int *a = new int[n + 1];
    // for (auto x : v) {
    //     cout << x << endl;
    // }
    a[0] = 0;
    n = v.size();
    Try(a, n, k, v, 1);
}
void Try(int *a, int n, int k, vector<string> v, int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            // for (int i = 1; i <= k; i++) {
            //     cout << a[i] << " ";
            // }
            // cout << endl;
            for (int i = 1; i <= k; i++) {
                cout << v[a[i] - 1] << " ";
            }
            cout << endl;
        } else {
            Try(a, n, k, v, i + 1);
        }
    }
}
