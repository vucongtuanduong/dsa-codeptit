#include <iostream>
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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
		bool swapped = false;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
        cout << "Buoc " << n - i << ": ";
        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
	}
}