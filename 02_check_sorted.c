#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];
    int sorted = 1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            sorted = 0;
            break;
        }
    }

    if(sorted == 1)
    {
        printf("Array is sorted.");
    }
    else
    {
        printf("Array is not sorted.");
    }

    return 0;
}