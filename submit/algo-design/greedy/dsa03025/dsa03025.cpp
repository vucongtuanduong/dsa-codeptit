#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
void testCase();
bool cmp(pair<int, int> a, pair<int, int>  b);
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
void testCase() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, cmp);
    int count = 1;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (a[j].first >= a[i].second) {
            count++;
            i = j;
        }
    }
    cout << count;
}
bool cmp(pair<int, int> a, pair<int, int>  b) {
    if (a.second == b.second) {
        return a.first < b.second;
    }
    return a.second < b.second;
}