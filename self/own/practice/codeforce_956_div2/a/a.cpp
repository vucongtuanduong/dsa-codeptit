#include <iostream>
#include <vector>
using namespace std;
void generate_beautiful_array(int n) {
    vector<int> a(n + 1, 1); 
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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
