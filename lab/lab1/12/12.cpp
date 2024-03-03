#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void testCase();

int main() {
    // Write your code here
    testCase();
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    int x;
    for (int i = 0; i < n / 2; i++) {
        cin >> x;
        a.push_back(x);
        cin >> x;
        b.push_back(x);
    }
    if (n  % 2 == 1) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n / 2; i++) {
        cout << a[i] << " " << b[i] << " ";
    }
    if(n % 2 == 1) {
        cout << a[n / 2];
    }
}