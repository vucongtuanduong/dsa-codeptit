#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
void testCase();
void Try(int i);
bool check();
void result();
int main() {
    // Write your code here
    testCase();
    return 0;
}
bool check() {
    int count0 = 0, count1 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            count0++;
        } else if (a[i] == 1) {
            count1++;
        }
    }
    int count2 = a.size() - count0 - count1;
    if (count0 > 0 && count1 > 0 && count2 > 0 && count0 <= count1 && count1 <= count2) {
        return true;
    } else {
        return false;
    }
}
void result() {
    for (int  i = 0; i < a.size(); i++) {
        cout << (char)(a[i] + 'A');
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j < 3; j++) {
        a[i] = j;
        if (i == a.size() - 1 ) {
            if (check()) {
                result();
            }
        } else {
            Try(i + 1);
        }
    }
}
void testCase() {
    cin >> n;
    a.clear();
    for (int x = 3; x <= n; x++) {
        a.resize(x);
        for (int i = 0; i < a.size(); i++ ){
            a[i] = i;
        }
        Try(0);

    }
}