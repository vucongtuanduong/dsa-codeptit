#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    string s;
    cin >> s;
    int n = s.size();
    string res = s;
    string fre = "";
    map<char,int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    for (auto x : mp) {
        fre += x.first;
    }
    int d=  2;
    int i = 0;
    int k  = mp.size();
    while (i < k) {
        char p = mp.begin()->first;
        for (int j = 0; j < mp[p]; j++) {
            if (i + (j * d) >= n) {
                cout << "-1";
                return;
            }
            res[i + (j * d)] = fre[i];
            
        }
        i++;
        mp.erase(p);
    }
    cout << "1";
}