#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> input, res;
map<string, int> mp;

void Try(int i) {
    if (i == n + 1) {
        return;
    }
    if (res.size() > 0) {
        string s = "";
        for (auto x : res) {
            s += x;
        }
        mp[s]++;
    }
    for (int j = i; j < n; j++) {
        res.push_back(input[j]);
        Try(j + 1);
        res.pop_back();
    }
}

void testCase() {
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    Try(0);
    for (auto x : mp) {
        cout << x.first << endl;
    }
}

int main() {
    testCase();
    return 0;
}