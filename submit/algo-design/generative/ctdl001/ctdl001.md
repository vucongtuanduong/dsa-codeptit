Một xâu nhị phân độ dài n được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu nhị phân đó ta vẫn nhận được chính nó. Cho số tự nhiên n (n nhập từ bàn phím). Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.  Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.

![Alt text](image.png)
Ví dụ\
Input 	Output\
4 	

0 0 0 0

0 1 1 0

1 0 0 1

1 1 1 1
## result
WA

## gpt4's code:
```
#include <iostream>
using namespace std;

void init(int *x, int n);
bool isFinal(int *x, int n);
void display(int *x, int n, bool reversed);
void genNext(int *x, int n);
void testCase();
int main() {
    testCase();
    return 0;
}

void init(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}

void genNext(int *x, int n) {
    int i = n;
    while (i > 0 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if (i > 0) {
        x[i] = 1;
    }
}

void display(int *x, int n, bool reversed) {
    for (int i = 1; i <= n; i++) {
        cout << x[reversed ? n - i + 1 : i] << " ";
    }
}

bool isFinal(int *x, int n) {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) return false;
    }
    return true;
}

void testCase() {
    int n;
    cin >> n;
    int *x = new int[n + 1];

    init(x, n / 2);
    do {
        display(x, n / 2, false); // Display the first half
        if (n % 2 == 1) cout << "0 "; // For odd n, add 0 in the middle
        display(x, n / 2, true); // Display the mirrored first half
        cout << endl;
        if (n % 2 == 1) {
            display(x, n / 2, false); // Display the first half again
            cout << "1 "; // For odd n, add 1 in the middle
            display(x, n / 2, true); // Display the mirrored first half
            cout << endl;
        }
        genNext(x, n / 2);
    } while (!isFinal(x, n / 2));

    // Display the final combination
    display(x, n / 2, false);
    if (n % 2 == 1) cout << "0 ";
    display(x, n / 2, true);
    cout << endl;
    if (n % 2 == 1) {
        display(x, n / 2, false);
        cout << "1 ";
        display(x, n / 2, true);
        cout << endl;
    }

    delete[] x;
}

```