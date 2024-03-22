#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
void testCase();
void Row();
void init();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        // cout << endl;
    }
    return 0;
}
void init() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void Row() {
    if (n == 0) {
        return ;
    } else {
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i != n - 1) {
                cout << " ";
            }
        }
        cout << "]\n";
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i] + a[i + 1];
        }
        n--;
        Row();
    }

}
void testCase() {
    init();
    Row();
} 