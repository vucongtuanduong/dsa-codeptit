#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ok = false;
void testCase();
void findCombinations(vector<int> a, int x, vector<int> &combination, int start);
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
void findCombinations(vector<int> a, int x, vector<int> &combination, int start){ 
    if (x == 0) {
        if (combination.size() != 0) {
            ok = true;
        }
        cout << "[";
        for (int i = 0; i < combination.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << combination[i];
            
        }
        cout << "]";
        return;
    }
    for (int i = start; i < a.size(); i++) {
        if (a[i] <= x) {
            combination.push_back(a[i]);
            findCombinations(a, x  - a[i], combination, i );
            combination.pop_back();
        }
    }
}
void testCase() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> combination;
    findCombinations(a, x, combination, 0);
    if (!ok) {
        cout << "-1";
        return;
    }
    ok = false;

}