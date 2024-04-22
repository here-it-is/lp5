#include <iostream>
#include <omp.h>
using namespace std;
void parallelBubblesort(int arr[], int n)
{
    int i, j;
#pragma omp parallel for private(i, j) shared(arr, n)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    const int size = 10;
    int arr[size] = {64, 25, 34, 9, 56, 87, 23, 98, 22, 10};
    double start_time = omp_get_wtime();
    parallelBubblesort(arr, size);
    double end_time = omp_get_wtime();
    cout << "Sorted array using parallel bubble sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "Parallel bubble sort time: " << end_time - start_time << " seconds\n";
    return 0;
}
