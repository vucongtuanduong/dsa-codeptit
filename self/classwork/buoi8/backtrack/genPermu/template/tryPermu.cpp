#include <bits/stdc++.h>
using namespace std;
int n;
int x[101];
bool chuaxet[101];
void init();
void Try(int i);
void result();
int main () {
    init();
    Try(1);
    return 0;
}
void result() {
    for (int i =1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        chuaxet[i] = true;
    }
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (chuaxet[j]) {
            x[i] = j;
            chuaxet[j] = false;
            if (i == n) {
                result();
            } else {
                Try(i + 1);
            }
            chuaxet[j] = true;
        }
        
    }
}