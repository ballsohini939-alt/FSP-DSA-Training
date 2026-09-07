#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;
    int depth = 0;

    printf("Enter parentheses string: ");
    scanf("%s", str);

    printf("String after removing outermost parentheses: ");

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == '(')
        {
            if(depth > 0)
            {
                printf("(");
            }

            depth++;
        }
        else if(str[i] == ')')
        {
            depth--;

            if(depth > 0)
            {
                printf(")");
            }
        }
    }

    return 0;
}