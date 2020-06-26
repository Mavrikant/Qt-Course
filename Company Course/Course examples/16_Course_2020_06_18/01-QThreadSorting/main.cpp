#include <QCoreApplication>
#include <bublesort.h>
#include <bits/stdc++.h>
#include <QRandomGenerator>
#include <QMutex>
using namespace std;
const size_t ArraySize = 1024;
/* Function to print an array */
void printArray(int arr[], size_t size)
{
    size_t i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void random_array(int *array, size_t size, int min, int max)
{
    unsigned int umax = abs(max - min);
    for (size_t i = 0; i < size; i++)
    {
        array[i] = min + QRandomGenerator::global()->generate() % umax;
    }
}
struct MyComparer
{
    template<typename T1>
    bool operator()(const T1 &a, const T1 &b) const
    {
        return a < b;
    }
};
// Driver code
int main()
{
    int arr[ArraySize];
    size_t n = sizeof(arr) / sizeof(arr[0]);
    //bubbleSort(arr, n);
    //selectionSort(arr,n);
    random_array(arr, ArraySize, -500, 500);
    // Ordering ascending
    sort(begin(arr), end(arr), MyComparer());

    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;

}

// This code is contributed by rathbhupendra

