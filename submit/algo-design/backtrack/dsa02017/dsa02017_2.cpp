#include <bits/stdc++.h>
using namespace std;
int mat[8][8];
bool a[101],xuoi[101],nguoc[101];
int x[101];
int res = 0;
int n= 8;
void init();
void testCase();
void Try(int i);
void result();
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
void result() {
    int temp = 0;
    for (int i = 1; i <= 8; i++) {
        temp += mat[i - 1][x[i] - 1];
    }
    res = max(res, temp);
}
void Try(int i) {
    for (int j = 1; j <= 8; j++) {
        if (!a[j] && !xuoi[i + j - n] && !nguoc[i - j + 1]) {
            x[i] = j;
            a[j] = true;//cot
            xuoi[i + j - n] = true;
            nguoc[i - j + 1] = true;
            if (i == 8) {
                result();
            } else {
                Try(i + 1);
            }
            a[j] = false;//cot
            xuoi[i + j - n] = false;
            nguoc[i - j + 1] = false;
        }
    }
}
void init() {
    res = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= 8; i++) {
        a[0] = false;

    }
    for (int i = 1; i <= 16; i++) {
        xuoi[i] = false;
        nguoc[i] = false;
    }
}
void testCase() {
    init();
    Try(1);
    cout << res;
}