#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;

// Push character into stack
void push(char ch)
{
    top++;
    stack[top] = ch;
}

// Pop character from stack
char pop()
{
    return stack[top--];
}

int main()
{
    char str[MAX];
    int i;
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Push each character into stack
    for(i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }
    printf("Reversed string: ");

    // Pop characters to reverse the string
    while(top != -1)
    {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}
