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
    int n;
    cin >> n;
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 0) {
            count[x % 10] = 1;
            x /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (count[i] == 1) {
            cout << i << " ";
        }
    }
}