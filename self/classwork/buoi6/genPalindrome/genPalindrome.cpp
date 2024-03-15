#include <iostream>
using namespace std;
void init(int *x, int n);
bool isFinal(int *x, int n);
void display(int *x ,int n);
void genNext(int *x, int n);
bool check(int *x, int n);
void testCase2();
int main () {
    testCase2();
    return 0;
}
void init(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}
void genNext(int *x, int n) {
    int i = n;
    while (i > 0 && x[i] == 1) {
        i--;
    }
    x[i] = 1;
    for (int j = i + 1; j <= n; j++) {
        x[j] = 0;
    
    }
}
void display(int *x ,int n) {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
}
bool isFinal(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            return false;
        }
    }
    return true;

}
void testCase2() {
    int n;
    cin >> n;
    int *x = new int[n + 1];
    init(x, n);
    while (!isFinal(x, n)) {
        if (check(x, n)) {
            display(x, n);
            cout << endl;
        }
        genNext(x, n);
    }
    display(x, n);
    cout << endl;
}
bool check(int *x, int n) {
    for (int i = 1; i <= n / 2; i++) {
        if (x[i] != x[n - i + 1]) {
            return false;
        }
    }
    return true;
}