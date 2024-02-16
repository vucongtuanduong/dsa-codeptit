#include <iostream>
#include <algoirhtm>
using namespace std;
void selectionSort(int *a, int l, int r);
void insertionSort(int *a, int l, int r);
int main () {

    return 0;
}
void selectionSort(int *a, int l, int r) {
    for (int i = l; i < r; i++) {
        int min = i;
        for (int j = i = 1; j <= r; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a[min], a[i]);
        }
    }
}
void insertionSort(int *a, int l, int r){
    for (int i = l + 1; i <= r; i++) {
        int temp = a[i];
        int j = i;
        for (; j > l && temp < a[j - 1]; j--) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}