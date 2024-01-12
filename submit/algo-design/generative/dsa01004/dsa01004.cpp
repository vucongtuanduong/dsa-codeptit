#include <iostream>
using namespace std;
void testCase();
void init(int *x, int k);
void display(int *x, int k);
bool isFinal(int *x, int n, int k);
void genNext(int *x, int n, int k);
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
    init(x, k);
    display(x, k);
    while (!isFinal(x, n, k)) {
        
        genNext(x, n, k);
        display(x, k);
    }
}
void init(int *x, int k) {
    for (int i = 1; i <= k; i++) {
        x[i] = i;
    }
}
void display(int *x, int k) {
    for (int i = 1; i <= k; i++) {
        cout << x[i];
    }
    cout << " ";
}
bool isFinal(int *x, int n, int k) {
    for (int i = 1; i <= k; i++) {
        if (x[i] != n - k + i) {
            return false;
        }
    }
    return true;
}
void genNext(int *x, int n, int k) {
    int i = k;
    while (x[i] == (n - k + i)) {
        i--;
    }
    x[i]++;
    for (int j = i+ 1 ; j <= k; j++) {
        x[j] = x[j - 1] + 1;
    }
}
