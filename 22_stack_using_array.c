#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;

// Push element into stack
void push(int data)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = data;

        printf("%d pushed into stack.\n", data);
    }
}

// Pop element from stack
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Peek top element
void peek()
{
    if(top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display stack
void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements: ");

        for(i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}
int main()
{
    int choice;
    int data;
    do
    {
        printf("\n--- STACK USING ARRAY ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}

