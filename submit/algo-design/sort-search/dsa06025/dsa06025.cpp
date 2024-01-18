#include <iostream>
#include <vector>
using namespace std;
void testCase();
void insertionSort(vector<int> &a, int l, int r);
int main() {
    // Write your code here
    testCase();

    return 0;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a, 0, n - 1);

}
void insertionSort(vector<int> &a, int l, int r) {
    cout << "Buoc 0: " << a[l] << endl; // "Buoc 0: 1
    for (int i = l + 1; i <= r; i++) {
        int key = a[i];
        int j = i; 
        for (; j > l && a[j - 1] > key; j--) {
            a[j] = a[j - 1];
        }
        a[j] = key;
        cout << "Buoc " << i << ": ";
        for (int k = l; k <= i; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}