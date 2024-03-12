#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void testCase();
void testCase2();
int main() {
    // Your code here
    testCase2();
    return 0;
}
void testCase2() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> prefixMin(n, INT_MAX);//running from 0 to i
    vector<int> suffixMin(n, INT_MAX);//running from i + 1 to n
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            prefixMin[i] = i > 0 ? min(prefixMin[i - 1], a[i]) : a[i];
        } else if (i > 0) {
            prefixMin[i] = prefixMin[i - 1];
        }
    }
    
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            bool isOdd = false;
            for (int j = i + 1; j < n; j++) {
                if (a[j] % 2 == 1) {
                    isOdd = true;

                } else if (isOdd == true && a[j] < a[i] && a[j] % 2 == 0) {
                    count++;
                }
            }
        }
        
    }
    cout << count;
    //O(n^2) -> TLE
}