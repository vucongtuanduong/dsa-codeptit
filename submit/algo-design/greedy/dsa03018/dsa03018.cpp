#include <bits/stdc++.h>
using namespace std;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int num7s = n / 7;
    n %= 7;
    while (num7s > 0) {
        if (n % 4 == 0) {
                for (int i = 0; i < n / 4; i++) {
                cout << "4";
            }
            for (int i = 0; i < num7s; i++) {
                cout << "7";
                
            }
            return;
        }
        
        
        n += 7;
        num7s--;
    }
    cout << "-1";
}