#include <iostream>
using namespace std;
void testCase();
bool isFinal(int *x, int n, int k);
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
    int n, k;
    cin >> n >> k;
    int *x = new int[n + 1];
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    int t = k;
    while (t > 0 && x[t] == (n - k + t)) {
        t--;
    }
    cout << (k - t);

}
