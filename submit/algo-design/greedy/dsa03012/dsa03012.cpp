#include <iostream>
#include <map>
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
    map<char,int> mp;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    string res = s;
    string fre = "";
    for (auto x : mp) {
        fre += x.first;
    }
    int i = 0;
    int k = mp.size();
    int d = 2;
    while (i < k) {
        char p = mp.begin()->first;
        for (int t = 0; t < mp[p]; t++) {
            if (i + (t * d) >= n) {
                cout << "-1";
                return;
            }
            res[i + (t * d)] = fre[i];
        }
        
        i++;
        mp.erase(p);
    }
    cout << "1";
}