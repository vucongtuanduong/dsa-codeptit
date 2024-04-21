#include <bits/stdc++.h>
using namespace std;
void testCase( ){
    int num;
    string s;
    cin >> num >> s;
    // cout << num << " " << s << endl;
    int n = s.size();
    int j = n - 2;
    while (j >= 0 && s[j] >= s[j + 1]) {
        j--;
    }
    if (j == -1) {
        cout << num << " BIGGEST";
        return;
    }
    int k = n - 1;
    while (s[j] >= s[k]) {
        k--;
    }
    swap(s[j], s[k]);
    reverse(s.begin() + j + 1, s.end());
    cout << num << " " << s;
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
