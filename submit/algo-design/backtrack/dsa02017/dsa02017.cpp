#include <bits/stdc++.h>
using namespace std;

int A[8][8], row[8], maxScore;

bool place(int r, int c) {
    for (int prev = 0; prev < c; prev++)
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;
    return true;
}

void backtrack(int c) {
    if (c == 8) {
        int score = 0;
        for (int i = 0; i < 8; i++)
            score += A[i][row[i]];
        maxScore = max(maxScore, score);
    }
    for (int r = 0; r < 8; r++)
        if (place(r, c)) {
            row[c] = r;
            backtrack(c + 1);
        }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> A[i][j];
        maxScore = -1;
        backtrack(0);
        cout << maxScore << endl;
    }
    return 0;
}