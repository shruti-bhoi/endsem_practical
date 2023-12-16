#include <iostream>

using namespace std;

void maxHeap(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) 
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) 
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeap(arr, n, largest);
    }
}

void minHeap(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) 
    {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) 
    {
        smallest = right;
    }

    if (smallest != i) 
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeap(arr, n, smallest);
    }
}

void heapSort(int arr[], int n, bool ascending) 
{
    if (ascending) 
    {
        for (int i = n / 2 - 1; i >= 0; --i) 
        {
            maxHeap(arr, n, i);
        }

        for (int i = n - 1; i > 0; --i) 
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            maxHeap(arr, i, 0);
        }
    }
     else 
     {
       
        for (int i = n / 2 - 1; i >= 0; --i) 
        {
            minHeap(arr, n, i);
        }

        for (int i = n - 1; i > 0; --i) 
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            minHeap(arr, i, 0);
        }
    }
}

int main() 
{
    int n, i;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    bool ascending;
    cout << "Choose sorting order:\n1. Ascending\n2. Descending\nEnter your choice: ";
    int choice;
    cin >> choice;

    ascending = (choice == 1);

    heapSort(arr, n, ascending);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
  return 0;
}
