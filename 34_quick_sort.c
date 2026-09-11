#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for(j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivotIndex;
        pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    int arr[100];
    int n;
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display unsorted array
    printf("\nUnsorted array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Sort the array
    quickSort(arr, 0, n - 1);

    // Display sorted array
    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

