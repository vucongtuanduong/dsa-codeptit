#include <bits/stdc++.h>
using namespace std;
vector<int> res;
void doIncreasingNum(int n) {
    if (n == 0) {
        return;
    }
    doIncreasingNum(n - 1);
    res.push_back(n);
}
vector<int> increasingNumbers(int n) {
    doIncreasingNum(n);
    return res;
}
int main() {
    // Write your code here
    int n;
    cin >> n;
    res.clear();
    vector<int> result = increasingNumbers(n);
    for (auto x : res) {
        cout << x << " ";
    }
    return 0;
}
