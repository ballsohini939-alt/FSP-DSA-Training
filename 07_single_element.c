#include <stdio.h>

int main()
{
    int n, i, j;
    int arr[100];
    int count;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        count = 0;

        for(j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        if(count == 1)
        {
            printf("Element occurring only once = %d", arr[i]);
            break;
        }
    }

    return 0;
}