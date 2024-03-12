#include <bits/stdc++.h>
using namespace std;
string s(8, '0');
vector<string> res;
void solve();
void testCase();
void Try(int i);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif
    testCase();
    return 0;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        if (j == 0) {
            s[i] = '0'; 
        } else {
            s[i] = '2';
        }
        if (i == 7) {
            solve();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    Try(0);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}
void solve() {
    // cout << s << endl;
    int d = stoi(s.substr(0, 2));
    int m = stoi(s.substr(2, 2));
    int y = stoi(s.substr(4));
    if (d > 0 && d <= 31 && m >0 && m < 12 && y >= 2000) {
        string temp = s;
        // cout << "s: " << s << endl;
        temp.insert(2, 1, '/');
        temp.insert(5, 1, '/');
        // cout << "temp: " << temp << endl; ;
        res.push_back(temp);

    }
}