#include <iostream>
#include <vector>
using namespace std;
void generate_beautiful_array(int n) {
    vector<int> arr(n, 1); // Initialize the array with all elements as 1
    for (int i = 2; i <= n; i++) {
        arr[i - 1] = i * i; // Set the ith element to i^2 for each index divisible by i
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        generate_beautiful_array(n);
    }
    return 0;
}
