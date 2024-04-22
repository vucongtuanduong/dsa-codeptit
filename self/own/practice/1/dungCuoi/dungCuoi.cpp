#include <bits/stdc++.h>
using namespace std;
int n;
vector<string>x;
string ex;
int a[101];
bool unused[101];
void init();
void testCase();
void Try(int i);
int main() {
    // Write your code here
    testCase();
    return 0;
}

void init() {
    cin >> n;
    for (int i  = 0; i < n; i++) {
        string s;
        cin >> s;
        x.push_back(s);
    }
    cin >> ex;
    // cout << ex << endl;
    x.erase(find(x.begin(), x.end(), ex));
    
    sort(x.begin(), x.end());
    n--;
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
}
void Try(int i) {
    for (int j = 1; j <= n; j++ ){
        if (unused[j]) {
            unused[j] = false;
            a[i] = j;
            if (i == n) {
                for (int k = 1; k <= n; k++) {
                    cout << x[a[k] - 1] << " ";
                }
                cout <<  ex << endl;
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        } 
        
    }
    
}
void testCase() {
    init();
    Try(1);
}