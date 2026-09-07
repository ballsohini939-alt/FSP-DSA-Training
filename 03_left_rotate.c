#include <stdio.h>

int main()
{
    int n, k, i, j;
    int arr[100];
    int temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < k; i++)
    {
        temp = arr[0];

        for(j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }

        arr[n - 1] = temp;
    }

    printf("Array after left rotation:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}