#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b) {
    map<int, int> mp;
    for(auto x : a) {
        mp[x]++;
    }
    for(auto x : b) {
        mp[x]++;
    }
    int dem = 0;
    for(auto x : mp) {
        if(x.second == 2) {
            dem++;
        }
        if(dem == 2) {
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    for(int i = 0; i < n; i++) {
        for(auto &x : v[i]) {
            cin >> x;
        }
        sort(v[i].begin(), v[i].end());
    }

    int cnt = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++) {
        int j = i + 1;
        while(j < n && v[j][0] <= v[i][4]) {
            j++;
        }
        cnt += n - j;
        for(int k = i + 1; k < j; k++) {
            if(!check(v[i], v[k])) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
