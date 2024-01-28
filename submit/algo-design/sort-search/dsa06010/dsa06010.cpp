#include <iostream>
#include <algorithm>
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
    int n;
    cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            mp[s[j] - '0']++;
        }
    }
    for (map<int, int>:: iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " ";
    }
}