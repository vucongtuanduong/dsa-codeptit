#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

long long findRotations(long long a[], long long n) {
    long long low = 0, high = n - 1;
    while (low <= high) {
        if (a[low] <= a[high]) {
            return low;
        }
        int mid = (low + high) /2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
        if (a[mid] <= a[next] && a[mid] <= a[prev]) {
            return mid;
        } else if (a[mid] <= a[high] ){
            high = mid - 1;
        } else if (a[mid] >= a[low]) {
            low = mid + 1;
        }
    }
    return -1;
}

void testCase() {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << findRotations(a, n);
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}