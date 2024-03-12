#include <iostream>
#include <algorithm>
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
    int res = 0;
    //selection_sort
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[x]) {
                x = j;
            }
        }
        if (x != i) {
            res++;
            swap(a[x], a[i]);
        }   
    }
    cout << res ;
}