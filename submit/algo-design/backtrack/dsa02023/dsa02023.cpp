#include <iostream>
#include <map>
#include <vector>
using namespace std;
void testCase();
void Try(int i, int *a, vector<string> input, int k, int m);
void solve(int *a,vector<string> input, int k);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void solve(int *a,vector<string> input, int k) {
    // for (int i = 1; i <= k; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= k; i++) {
        cout << input[a[i] - 1] << " ";
    }
    cout << endl;
}
void Try(int i, int *a, vector<string> input, int k, int m) {
    for (int j = a[i - 1] + 1; j <= m - k + i; j++) {
        a[i] = j;
        if (i == k) {
            solve(a, input, k);
        } else {
            Try(i + 1, a, input, k, m);
        }
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<string> input;
    vector<string> res;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    for (auto x : mp) {
        input.push_back(x.first);
    }
    int m = input.size();
    int a[m + 1];
    a[0] = 0;
    Try(1, a, input, k, m);
}