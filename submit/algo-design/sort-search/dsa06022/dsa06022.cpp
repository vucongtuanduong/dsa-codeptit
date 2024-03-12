#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
void testCase();
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int min = a[0];
    int secondMin = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (a[i] > min) {
            secondMin = a[i];
            break;
        }
    
    }
    if (secondMin == INT_MAX) {
        cout << -1;
    } else {
        cout << min << " " << secondMin;
    }
}#include <iostream>
using namespace std;

int main() {
    // Write your code here
    return 0;
}
