#include <iostream>
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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int a[n1], b[n2], c[n3];
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n3; i++) {
        cin >> c[i];
    }
    int i = 0, j = 0, k = 0;
    bool ok = false;
    while (i < n1 && j < n2 && k < n3) {
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
        cout << "-1";
    }

}