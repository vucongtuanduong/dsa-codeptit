#include <iostream>
using namespace std;
void init(int *x, int n);
bool isFinal(int *x, int n);
void testCase();
void display(int *x ,int n, bool reversed);
void genNext(int *x, int n);

int main () {
    testCase();
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
void display(int *x ,int n, bool reversed) {
    if (reversed == false) {
        for (int i = 1; i <= n; i++) {
            cout << x[i] << " ";
        }
    } else {
        for (int i = n; i >= 1; i--) {
            cout << x[i] << " ";
        }
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
void testCase() {
    int n;
    cin >> n;
    int *x = new int[n + 1];
    if (n % 2 == 0) {
        n /= 2;
        init(x, n);
        while (!isFinal(x, n)) {
            display(x, n, false);
            display(x, n, true);
            cout << endl;
            genNext(x, n);
        }
    } else {
        n /= 2;
        init(x, n);
        while (!isFinal(x, n)) {
            for (int i = 0; i <= 1; i++) {
                display(x, n, false);
                cout << i << " ";
                display(x, n, true);
                cout << endl;
            }
            genNext(x, n);
        }
        for (int i = 0; i <= 1; i++) {
            display(x, n, false);
            cout << i << " ";
            display(x, n, true);
            cout << endl;
        }
    }
    

}