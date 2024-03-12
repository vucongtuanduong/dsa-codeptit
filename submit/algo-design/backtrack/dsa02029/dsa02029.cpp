#include <iostream>
using namespace std;
void testCase();
void tower(int n, char a, char b, char c);
int main() {
    // Your code here
    testCase();
    return 0;
}
void tower(int n, char a, char b, char c) {
    if (n == 1) {
        cout << a << " -> " << c << endl;
        return;
    }
    tower(n - 1, a, c, b);
    tower(1, a, b, c);
    tower(n - 1, b, a, c);
}
void testCase() {
    int n;
    cin >> n;
    tower(n, 'A', 'B', 'C');
}