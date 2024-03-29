#include <bits/stdc++.h>
using namespace std;
int n;
int x[101];
bool xuoi[101];
bool nguoc[101];
bool cot[101];
int res;
void init();
void Try(int i);
void result();
int main () {
    int t;
    cin >> t;
    while (t--) {
        init();
        Try(1);
        cout << res << endl;
    }
    
    return 0;
}
void result() {
    for (int i =1; i <= n; i++) {
        cout << "(" << i << ", " << x[i] << ") ";
        
    }
    // cout << endl;
}
void init() {
    cin >> n;
    res = 0;
    for (int i = 1; i <= n; i++) {
        cot[i] = true;
    }
    for (int i = 1; i <= 2 * n; i++) {
        
        xuoi[i] = true;
        nguoc[i] = true;
    }
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {//tu cot 1 den cot n
        if (cot[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            x[i] = j;
            cot[j] = false;
            xuoi[i - j + n] = false;
            nguoc[i + j - 1] = false;
            if (i == n) { 
                res++;
            } else {
                Try(i + 1);
            }
            cot[j] = true;
            xuoi[i - j + n] = true;
            nguoc[i + j - 1] = true;
        }
        
    }
}