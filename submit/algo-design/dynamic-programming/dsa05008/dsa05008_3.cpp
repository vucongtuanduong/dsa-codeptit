#include <bits/stdc++.h>
using namespace std;
void testCase() {
    int n, s;
    cin >> n >> s;
    int a[n];
    vector<bool> l(s + 1, false);
    l[0] = true;
    for (int i = 0; i < n; i++){ 
        cin >> a[i];
        for (int j = s; j >= a[i]; j--) {
            if (l[j] == false &&  l[j - a[i]] == true) {
                l[j] = 1;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
        
    // }
    if (l[s]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
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
