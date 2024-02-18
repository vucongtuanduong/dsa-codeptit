#include <iostream>
#include <algorithm>
using namespace std;

void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long max1 = a[n - 1] * a[n - 2] * a[n - 3];
    long long max2 = a[0] * a[1] * a[n - 1];
    cout << max(max1, max2);
}

int main() {
    testCase();
    return 0;
}