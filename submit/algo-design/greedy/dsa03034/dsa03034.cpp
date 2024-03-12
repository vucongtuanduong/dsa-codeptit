#include <iostream>
using namespace std;
void testCase();
void scanArray(int *a, int m);
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
    int m, n, p;
    cin >> m >> n >> p;
    int a[m], b[n], c[p];
    scanArray(a, m);
    scanArray(b, n);
    scanArray(c, p);
    bool ok = false;
    int i = 0, j = 0, k = 0;
    while (i < m && j < n && k < p) {
        if (a[i] == b[j] && b[j] == c[k]) {
            cout << a[i] << " ";
            ok = true;
            i++;
            j++;
            k++;
        } else if (a[i] < b[j]) {
            i++;
        } else if (b[j] < c[k]) {
            j++;
        } else {
            k++;
        }
    }
    if (!ok) {
        cout << "NO";
        return;
    }
}
void scanArray(int *a, int m) {
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
}