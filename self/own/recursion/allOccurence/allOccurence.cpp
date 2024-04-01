#include <bits/stdc++.h>
using namespace std;
vector<int> res;
void doFindAllOcc(vector<int> a, int k, int i) {
    if (i == a.size()) {
        return;
    }
    if (a[i] == k) {
        res.push_back(i);
    } 
    doFindAllOcc(a, k, i + 1);
}
void allOcc(vector<int> a, int n, int key) {
    res.clear();
    doFindAllOcc(a, key, 0);
}
int main() {
    // Write your code here
    int n, key;
    cin >> n >> key;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    allOcc(a, n, key);
    for (int i = 0; i < res.size(); i++ ){
        cout << res[i] << " ";
    }
    return 0;
}
