#include <iostream>
using namespace std;
void testCase();
int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];

    }
    cout << "Buoc 0: " << a[0] << endl;
    for (int i = 1; i < n; i++ ) {
        int key = a[i];
        int j = i;
        for (; j > 0 && a[j - 1] > key; j--) {
            a[j] = a[j - 1];
        }
        a[j] = key;
        cout << "Buoc " << i << ": " ;
        for (int k = 0; k <= i; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}