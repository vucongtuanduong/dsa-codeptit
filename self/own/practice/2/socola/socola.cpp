#include <iostream>
#include <vector>
using namespace std;
long long dp[35][35] = {};
void init() {
    
    dp[0][0] = 0;
    dp[0][1] = 1; 
    dp[1][0] = 1; 


    for (int i = 0; i <= 30; i++ ) {
        for (int j = 0; j <= 30; j++) {
            if (i == 0) {
                dp[i][j] = 1;

            }
            if (j == 0) {
                dp[i][j] = dp[i - 1][1];
            } 
            if (i > 0 && j > 0) {
                dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
            }
        }
    }
}
void testCase() {
    int n;
    cin >> n;
    cout << dp[n][0];
}
int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}