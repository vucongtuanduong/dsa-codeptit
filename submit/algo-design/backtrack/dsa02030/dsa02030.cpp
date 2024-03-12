#include <iostream>
using namespace std;
void testCase();
void Try(char a, char c, int n, string &b);
int main() {
    // Your code here
    testCase();

    return 0;
}
void testCase(){ 
    char a;
    int n;
    cin >> a >> n;
    string b;

    Try('A', a, n, b);
}
void Try(char a, char c, int n, string &b) {
    for (char j = a; j <= c; j++) {
        b.push_back(j);
        if (b.size() == n) {
            cout << b << endl;
        } else {
            Try(j, c, n, b);

        }
        b.pop_back();
    }
}