#include <bits/stdc++.h>
using namespace std;

void Try(vector<int> a, vector<string>&res, int start, string s, int count);
void testCase();

int main() {
    testCase();
    return 0;
}

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<string> res;
    for (int i = 0; i < n; i++) {
        Try(a, res, i, to_string(a[i]) + " ", 1);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

void Try(vector<int> a, vector<string>&res, int start, string s, int count) {
    for (int j = start + 1; j < a.size(); j++) {
        if (a[start] < a[j]) {
            string new_s = s + to_string(a[j]) + " ";
            int new_count = count + 1;
            if (new_count > 1) {
                res.push_back(new_s);
            }
            Try(a, res, j, new_s, new_count);
        }
    }
}