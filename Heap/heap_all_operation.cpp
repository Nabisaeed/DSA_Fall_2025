#include <iostream>
using namespace std;

// Heapify (Max Heap)
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build heap from array
void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Insert element into heap
void insert(int arr[], int& n, int value)
{
    arr[n] = value;
    int i = n;
    n++;

    // Heapify Up
    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Peek (get max element)
int peek(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    return arr[0];
}

// Extract / Delete max element
int extractMax(int arr[], int& n)
{
    if (n == 0)
    {
        cout << "Heap is empty\n";
        return -1;
    }

    int maxVal = arr[0];
    arr[0] = arr[n - 1];
    n--;

    heapify(arr, n, 0);
    return maxVal;
}

// Print heap
void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[100] = {4, 10, 3, 5, 1};
    int n = 5;

    cout << "Original Array:\n";
    printHeap(arr, n);

    buildHeap(arr, n);
    cout << "After Build Heap:\n";
    printHeap(arr, n);

    insert(arr, n, 15);
    cout << "After Insertion (15):\n";
    printHeap(arr, n);

    cout << "Peek (Max Element): ";
    cout << peek(arr, n) << endl;

    cout << "Extracted Max: ";
    cout << extractMax(arr, n) << endl;

    cout << "After Extraction:\n";
    printHeap(arr, n);

    return 0;
}
