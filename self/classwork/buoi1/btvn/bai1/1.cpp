#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
long long lcm(int a, int b) {
    int gcd_ab = gcd(a, b);
    long long res = a * b / gcd_ab;
    return res;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ucln = gcd(a, b);
        long long bcnn = lcm(a, b);
        cout << ucln << " " << bcnn << endl;
    }
    
    return 0;    
}