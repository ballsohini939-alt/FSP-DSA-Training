#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];
    int count = 0;
    int max = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements (0 or 1):\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(arr[i] == 1)
        {
            count++;

            if(count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 0;
        }
    }

    printf("Maximum consecutive ones = %d", max);

    return 0;
}