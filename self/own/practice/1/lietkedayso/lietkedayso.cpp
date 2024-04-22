#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int dd[4] = {2, 3, 5, 7};
bool check() {
    int count2 = 0, count3 = 0, count5 = 0, count7 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 2) {
            count2++;
        } else if (a[i] == 3) {
            count3++;
        } else if (a[i] == 5) {
            count5++;
        } else {
            count7++;
        }
    }
    int x = a.size() - 1;
    return (a[x] % 2 == 1 && count2 > 0 && count3 > 0 && count5 > 0 && count7 > 0);
}
void result() {
    if (check()) {
        for (int i = 0; i < a.size();i++ ){
            cout << a[i] ;
        }
        cout << endl;
    }
}
void Try(int i) {
    for (int j = 0; j < 4; j++) {
        a[i] = dd[j];
        if (i == a.size() - 1) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    cin >> n;
    for (int i = 4; i <= n; i++ ) {
        a.resize(i);
        Try(0);
    }

}
int main() {
    // Write your code here
    testCase();
    return 0;
}
