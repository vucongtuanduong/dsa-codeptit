#include <bits/stdc++.h>
using namespace std;
void testCase();
void tower(int n, char source, char helper, char dest);
int main() {
    // Write your code here
    testCase();
    return 0;
}
void tower(int n, char source, char helper, char dest) {
    if (n == 0) {
        return;
    }
    tower(n - 1, source, dest, helper);
    cout << source << " -> " << dest << endl;
    tower(n - 1, helper, source, dest);
}
void testCase() {
    int n;
    cin >> n;
    tower(n, 'A', 'B', 'C');
}