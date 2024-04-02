#include <bits/stdc++.h>
using namespace std;
int maxValue(vector<pair<int,int>> a, int weight) {
    int n = a.size();
    vector<int> dp(n + 1, 0);
    
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<pair<int,int>>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;//weight

        }   
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;//value
        }     
        cout << maxValue(a, w);
    }
    return 0;
}
