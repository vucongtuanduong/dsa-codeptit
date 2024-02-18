#include <iostream>
#include <vector>
using namespace std;
void testCase();
void Try(int i, vector<int> &a, vector<int> &res);
void print(vector<int> res);
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void print(vector<int> res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}
void Try(int i, vector<int> &a, vector<int> &res) {
    print(a);
    if (i == 1) {
        return;
    }
    for (int j = 0; j < i - 1; j++) {
        res.push_back(a[j] + a[j + 1]);

    }
    a = res;
    a.resize(i - 1);
    res.clear();
    Try(i - 1, a, res);
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> res;
    Try(n, a, res);
}