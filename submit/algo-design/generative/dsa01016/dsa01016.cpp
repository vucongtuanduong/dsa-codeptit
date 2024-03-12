#include <iostream>
#include <vector>
using namespace std;
void testCase();
void findCombinations(int n, int maxNum, vector<int>&combinations);
void result(vector<int> combinations);
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
void result(vector<int> combinations) {
    cout << "(";
    for (int i = 0;i < combinations.size(); i++) {
        cout << combinations[i];
        if (i != combinations.size() - 1) {
            cout << " ";
        }
    }
    cout << ") ";
}
void findCombinations(int n, int maxNum, vector<int>&combinations) {
    if (n == 0) {
        result(combinations);
        return;
    } 
    for (int i = min(n, maxNum); i >= 1; i--) {
        combinations.push_back(i);
        findCombinations(n - i, i, combinations);
        combinations.pop_back();
    }
}
void testCase() {
    int n;
    cin >> n;
    vector<int> combinations;
    findCombinations(n, n, combinations);
}