#include <iostream>
#include <omp.h>
#include<time.h>
using namespace std;

void parallel_bubble(int *arr, int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        #pragma omp parallel for shared(arr)
        for (int j = 1; j < (n - i); j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void bubble(int *arr, int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < (n - i); j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];
    clock_t start=clock();
    cout << "Enter " << n << " elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    parallel_bubble(arr, n);
    clock_t stop=clock();
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl ;
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Start : " <<  start << endl ;
    cout << "End : " << stop << endl ;
    cout << "Performance : " << elapsed ;
    return 0;
}
