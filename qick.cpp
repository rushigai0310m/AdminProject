#include <bits/stdc++.h>
#include <omp.h>
#include <time.h>
using namespace std;

void swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot)
{
    int i = low;
    int j = low;
    while (i <= high)
    {
        if (arr[i] > pivot)
        {
            i++;
        }
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        // quickSort(arr, low, pos-1);
        // quickSort(arr, pos+1, high);

        #pragma omp parallel sections
        {
        #pragma omp section
            {
             quickSort(arr, low, pos-1);
            }
        #pragma omp section
            {
             quickSort(arr, pos+1, high);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    clock_t start = clock();
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    clock_t stop = clock();
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // Calculate the elapsed time in milliseconds
	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	cout << "\nTime Elapsed In ms: " << elapsed;
}