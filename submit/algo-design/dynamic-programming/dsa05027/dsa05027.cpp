#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
void testCase();
bool cmp(pair<int,int>a, pair<int, int> b);
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
bool cmp(pair<int,int>a, pair<int, int> b) {
    return (1.0 * a.first / a.second) > (1.0 * b.first / b.second);
}
void testCase() {
    int  n, v;
    pair<int,int> knapsack[n];
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        cin >> knapsack.second[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> knapsack.first[i];
    }
    sort(a, a + n, cmp);
}