#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int i, j, k;
    int maxLength = 0;
    int endIndex = 0;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    for(i = 0; i < strlen(str1); i++)
    {
        for(j = 0; j < strlen(str2); j++)
        {
            k = 0;

            while(str1[i + k] == str2[j + k] &&
                  str1[i + k] != '\0' &&
                  str2[j + k] != '\0')
            {
                k++;
            }

            if(k > maxLength)
            {
                maxLength = k;
                endIndex = i + k;
            }
        }
    }

    printf("Longest Common Substring: ");

    for(i = endIndex - maxLength; i < endIndex; i++)
    {
        printf("%c", str1[i]);
    }

    printf("\nLength = %d", maxLength);

    return 0;
}