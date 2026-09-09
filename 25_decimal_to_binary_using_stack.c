#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;

// Push element into stack
void push(int data)
{
    top++;
    stack[top] = data;
}

// Pop element from stack
int pop()
{
    return stack[top--];
}
int main()
{
    int decimal;
    int remainder;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    if(decimal == 0)
    {
        printf("Binary number: 0\n");
        return 0;
    }

    // Convert decimal to binary
    while(decimal > 0)
    {
        remainder = decimal % 2;
        push(remainder);
        decimal = decimal / 2;
    }
    printf("Binary number: ");

    // Pop elements to get binary number
    while(top != -1)
    {
        printf("%d", pop());
    }
    printf("\n");
    return 0;
}

