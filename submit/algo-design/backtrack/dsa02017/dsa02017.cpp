#include <bits/stdc++.h>
using namespace std;
int a[8][8], row[8], maxScore;
void testCase();
void Try(int i);
bool place(int r, int c);
int main() {
    // Write your code here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
bool place(int r, int c) {
    for (int prev = 0; prev < c; prev++)
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;
    return true;
}
void Try(int i) {
    if (i == 8) {
        int score = 0;
        for (int i = 0; i < 8; i++) {
            score += a[i][row[i]];
        }
        maxScore = max(maxScore, score);
    }
    for (int r = 0; r < 8; r++) {
        if (place(r, i)) {
            row[i] = r;
            Try(i + 1);
        }
    }
}
void testCase() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> a[i][j];
        }
    }
    maxScore = -1;
    Try(0);
    cout << maxScore;
}