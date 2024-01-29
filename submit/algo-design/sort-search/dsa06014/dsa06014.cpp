#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX_SIZE = 1e6 + 1;
int prime[MAX_SIZE] = {0};
void testCase();
void sieve();
int main() {
    // Write your code here
    int t;
    cin >> t;
    sieve();
    while (t--) {
        testCase();
        cout << endl;
    }
    // delete prime;
    return 0;
}
void sieve() {
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i <= sqrt(MAX_SIZE); i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < MAX_SIZE; j += i) {
                prime[j] = 1;
            }
        }
        
    }
}
void testCase() {
    int n;
    cin >> n;
    int x = n / 2;
    for (int i = 2; i <= x; i++) {
        if (prime[i] == 0 && prime[n - i] == 0) {
            cout << i << " " << n - i;
            return;
        }
    }
    cout << "-1";
}