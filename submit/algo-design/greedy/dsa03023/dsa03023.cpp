#include <bits/stdc++.h>
using namespace std;
bool comp(char a, char b) {
    return a > b;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    string st = s;
    sort(s.begin(), s.end(), comp);
    // cout << "After sorted: s = " << s << ", st = " << st << endl;
    int d1 = 0, d2 = 0;
    multiset<string> ms;
    for (int i = 0; i < n; i++)
        if (st[i] != s[i]) {
            string ss = "";
            ss += st[i];
            ss += s[i];
            string rs = "";
            rs += s[i];
            rs += st[i];
            // cout << "ss: " << ss << endl;
            // cout << "rs: " << rs << endl;
            if (ms.count(rs)) {
                auto it = ms.find(rs);
                ms.erase(it);
                d1++;
            } else
                // cout << "insert ss\n";
                ms.insert(ss);
        }
    d2 = ms.size();
    cout << d1 + ((d2 / 3) * 2);
}
