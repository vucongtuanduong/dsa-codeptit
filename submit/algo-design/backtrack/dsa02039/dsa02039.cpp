#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void testCase();
void findCombinations(int sum, int maxNum, vector<int> &combination);
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
void findCombinations(int sum, int maxNum, vector<int> &combination) {
    if (sum == 0) {
        res.push_back(combination);
    }
    for (int i = min(sum, maxNum); i >= 1; i--) {
        combination.push_back(i);
        findCombinations(sum - i, i, combination);
        combination.pop_back();
    }
}
void testCase() {
    int n;
    cin >> n;
    vector<int> combination;
    res.clear();
    findCombinations(n, n, combination);
    cout << res.size() << endl;
    for (auto com: res) {
        cout << "(";
        for (int i = 0; i < com.size(); i++) {
            cout << com[i] ;
            if (i != com.size() - 1) {
                cout << " ";
            }
        }
        cout << ") ";
    }
}