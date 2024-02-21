#include <iostream>
#include <vector>
using namespace std;
void testCase();
void Try(int i, int *a, int n, int k, vector<vector<int>> &res);
int main() {
    // Write your code here
    testCase();

    return 0;
}
bool check(int *a, int n, int k) {
    int count0s = 0;
    int total0s = 0;
    bool is0 = false;
    if (a[0] == 0) {
        is0 = true;
        count0s = 1;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i < n; i++) {
        if (a[i] == 0 && is0 == true) {
            count0s ++;
        } else if (a[i] == 0 && is0 == false) {
            is0 = true;
            count0s = 1;
        } else if (a[i] == 1) {
            if (count0s == k) {
                total0s++;
            }
            is0 = false;
            count0s = 0;
        }
    }
    if (count0s == k && is0 == true) {
        total0s++;
    }
    // cout << "Total 0: " << total0s << endl;
    return total0s == 1;
}
void Try(int i, int *a, int n, int k, vector<vector<int>> &res) {
    for(int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n - 1) {
            if (check(a, n, k)) {
                vector<int> temp(a, a + n);
                res.push_back(temp);
            }
        } else {
            Try(i + 1, a, n, k, res);
        }
    }
}
void testCase() {
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<vector<int>> res;
    Try(0, a, n, k, res);
    cout << res.size() << endl;
    for (auto x : res) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == 0) {
                cout << "A";
            } else {
                cout << "B";
            }
        }
        cout << endl;
    }
}