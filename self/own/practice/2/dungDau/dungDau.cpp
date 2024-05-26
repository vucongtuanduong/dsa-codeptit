#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> a;
int x[101];
bool unused[101];
string ex;
void result() {
    cout << ex << " ";
    for (int i = 1; i <= n; i++) {
        cout << a[x[i] - 1] << " ";
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            unused[j] = false;
            x[i] = j;
            if (i == n) {
                result();
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}
void testCase() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    
    cin >> ex;
    int index;
    for (int i = 0; i < n; i++) {
        if (a[i] == ex) {
            index = i;
            break;
        }
    }
    a.erase(a.begin() + index);
    n--;
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
    Try(1);
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
