#include <iostream>
using namespace std;
int n;
int x[100];
bool a[100], xuoi[100], nguoc[100];
int count = 0;
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (a[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            x[i] = j;
            a[j] = false;
            xuoi[i - j + n] = false;
            nguoc[i + j - 1] = false;
            if (i == n) {
                count++;
            } else {
                Try(i + 1);
            }
            a[j] = true;
            xuoi[i - j + n] = true;
            nguoc[i + j - 1] = true;
        }
    }
}
void testCase ( );
int main ( ){
    
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase ( ){
    count = 0;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        a[i] = true;
        nguoc[i] = true;
        xuoi[i] = true;
        
    }
    Try(1);
    cout << count;
}