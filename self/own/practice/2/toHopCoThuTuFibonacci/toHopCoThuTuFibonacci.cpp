#include <bits/stdc++.h>
using namespace std;
int n, k;
long long fibo[93] = {0};
void init() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 93; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
int main() {
    // Write your code here
    return 0;
}
