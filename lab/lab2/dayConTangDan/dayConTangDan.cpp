#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> x;
void result() {
    if (count(x.begin(), x.end(), 1) >= 2) {
        for (int i = 0; i < n; i++){ 
            if (x[i] == 1) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n - 1) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    
    cin >> n;
    a.resize(n);  
    x.resize(n);  
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    Try(0);
}
int main() {
    // Write your code here
    testCase();
    return 0;
}
