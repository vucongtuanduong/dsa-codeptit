#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int d;
    cin >> d;
    string s;
    cin >> s;
    map<char,int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    string res = s;
    string fre = "";
    for (auto x : mp) {
        fre += x.first;
    }
    int i = 0;
    int k = mp.size();
    while (i < k) {
        char p = mp.begin()->first;
        for (int t = 0; t < mp[p]; t++) {
            if (i + (t * d) > s.size()) {
                cout << "-1";
                return;
            }
            res[i + t * d] = fre[i];
        }
        i++;
        mp.erase(p);
    }
    cout << "1";

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
