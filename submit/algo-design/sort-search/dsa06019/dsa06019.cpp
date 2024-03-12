#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void testCase();
bool cmp(pair<int,int> a, pair<int,int> b);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second > b.second) return true;
    if (a.second == b.second){
        if (a.first < b.first) {
            return true;
        }
    }
    return false;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    vector<pair<int,int>> v;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // cout << a[i] << " ";
        mp[a[i]]++;
    }
    for (auto i : mp) {
        v.push_back(make_pair(i.first, i.second));
    }
    sort(v.begin(), v.end(), cmp);  
    for (auto i : v) {
        while (i.second--) {
            cout << i.first << " ";
        }
    }
}