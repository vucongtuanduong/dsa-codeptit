#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
vector<int> input;
vector<int> precedence;
bool ok = false;
void check() {
    if (input == a) {
        ok = true;
        for (int i = 1; i <= k; i++) {
            cout << precedence[i] << " ";
        }
        return;
    } else {
        precedence = input;
    }
}
void Try(int i) {
    for (int j = input[i - 1] + 1; j <= (n - k + i); j++) {
        input[i] = j;
        if (ok == true) {
            return;
        }
        if (i == k) {
            check(); 
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    cin >> n >> k;
    ok = false;
    a.resize(k + 1);
    input.resize(k + 1);
    precedence.resize(k + 1);
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] == i) {
            cnt++;
        }
    }
    if (cnt == k) {
        for (int i = 1; i <= k; i++ ){
            cout << (n - k + i) << " ";
        }
        return;
    }
    Try(1);
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
