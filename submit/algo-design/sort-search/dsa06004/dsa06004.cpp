#include <iostream>
#include <map>
using namespace std;
void testCase();
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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    map<int,int> inter;
    map<int,int> unionMap;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        unionMap[a[i]]++;
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        if (unionMap[b[j]] == 0) {
            unionMap[b[j]]++;
        } else {
            inter[b[j]]++;
        }
    }
    for (auto x : unionMap) {
        cout << x.first << " ";
    }
    cout << endl;
    for (auto x : inter) {
        cout << x.first << " ";
    }
}