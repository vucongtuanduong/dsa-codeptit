#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void testCase();
void Try(vector<int> a,vector<int>&found, vector<vector<int>> &res, int target, int start);
void result(vector<vector<int>> res);
int main () {
    testCase();
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<int>found;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    // sort(a.begin(), a.end());
    Try(a, found, res, k, 0);
    result(res);
    cout << res.size() << endl;
}
void Try(vector<int> a,vector<int>&found, vector<vector<int>> &res, int target, int start) {
    if (target == 0) {
        res.push_back(found);
        return;
    }
    for (int i = start; i < a.size(); i++) {
        if (a[i] > target) {
            continue;
        }
        found.push_back(a[i]);
        Try(a, found, res, target - a[i], i + 1);
        found.pop_back();
    }


}
void result(vector<vector<int>> res) {
    vector<vector<int>> temp = res;
    reverse(temp.begin(), temp.end());
    for (auto x : temp) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
}