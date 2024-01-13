#include <iostream>
using namespace std;
void testCase();

int main() {
    // Your code here
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
    int *x = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    

}
