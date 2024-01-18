#include <iostream>
#include <vector>
using namespace std;
void testCase();
void insertionSort(vector<vector<int>> &res,vector<int> &a, int l, int r);
int main() {
    // Write your code here
    testCase();

    return 0;
}
void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(res,  a, 0, n - 1);

}
void insertionSort(vector<vector<int>> &res,vector<int> &a, int l, int r) {
    // cout << "Buoc 0: " << a[l] << endl; // "Buoc 0: 1
    res.push_back(a);
    for (int i = l + 1; i <= r; i++) {
        int key = a[i];
        int j = i; 
        for (; j > l && a[j - 1] > key; j--) {
            a[j] = a[j - 1];
        }
        a[j] = key;
        res.push_back(a);
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i << ": ";
        for (int j = 0; j < i + 1; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
