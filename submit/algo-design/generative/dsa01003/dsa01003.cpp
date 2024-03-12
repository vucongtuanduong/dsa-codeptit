#include <iostream>
#include <algorithm>
using namespace std;
void testCase();
void next_permu(int *x, int n);
void swap(int &a, int &b);
int main() {
    // Your code here
    int t;
    cin >> t;
    // cin.ignore();
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    // getchar();
    int *x = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    next_permu(x, n);
}  
void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}
void next_permu(int *x, int n) {
    int t = n -1;
    while (t >= 1 &&  x[t] > x[t + 1]) {
        t--;
    }
    if (t < 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }

        return;
    }
    
    int k = n;
    while (k >= 1 && x[k] < x[t]) {
        k--;
    }
    
    swap(x[t], x[k]);
    
    int l = t + 1, r = n;
    while (l <= r) {
        swap(x[l], x[r]);
        l++;
        r--;
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
}