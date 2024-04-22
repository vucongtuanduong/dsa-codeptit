#include <bits/stdc++.h>
using namespace std;
char c;
int n;
int x[101];
bool unused[101];
void testCase();
void init();
bool check();
void result();
bool isConsonant(int x);
void Try(int i);
int main() {
    // Write your code here
    testCase();
    return 0;
}
bool isConsonant(int x) {
    if (x == 1 || x == 5) {
        return true;
    }
    return false;
}
void result() {
    for (int i = 1; i <= n; i++) {
        cout << (char)(x[i] + 'A' - 1);
    }
    cout << endl;
}
bool check() {
    for (int i = 2; i < n; i++) {
        if (!isConsonant(x[i - 1]) && isConsonant(x[i]) && !isConsonant(x[i + 1])) {
            return false;
        }
    }
    return true;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            x[i] = j;
            unused[j] = false;
            if (i == n) {
                if (check()) {
                    result();
                }
                // result();
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}
void init() {
    cin >> c;
    n = c - 'A' + 1;
    for (int i = 1; i <= n; i++) {
        x[i]  = i;
        unused[i] = true;
    }
}
void testCase() {
    init();
    Try(1);
}