#include <iostream>
#include <set>
using namespace std;
void testCase();
void Try(int *np, int *x, int n, int k, int i);
bool check(int *np, int *x, int n, int k);
void result(int *np, int *x, int n);
int main() {
    // Your code here
    testCase();
    return 0;
}
void testCase() {
    int n, k;
    cin >> n >> k;
    int *x = new int[n + 1];
    set<int> s;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    int count = 1;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        x[count] = *it;
        count++;
    }
    count--;
    int *np = new int[count + 1];
    Try(np, x, count, k , 1);

}
void Try(int *np, int *x, int n, int k, int i) {
    for (int j = 0; j <= 1; j++) {
        np[i] = j;
        if (i == n) {
            if (check(np, x, n, k)) {
                result(np, x, n);
            }
        } else {
            Try(np, x, n, k, i + 1);
        }
    }
}
bool check(int *np, int *x, int n, int k) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (np[i] == 0) {
            count++;
            // cout << "count: " << count << endl;
        }
    }
    return (count == k);
}
void result(int *np, int *x, int n) {
    for (int i = 1; i <= n; i++) {
        if (np[i] == 0) {
            cout << x[i] << " ";
        }
    }
    cout << endl;
}