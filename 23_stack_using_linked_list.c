
#include <stdio.h>
#include <stdlib.h>

// Stack node
struct node
{
    int data;
    struct node *next;
};

// Push element into stack
void push(struct node **top, int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *top;

    *top = newNode;

    printf("%d pushed into stack.\n", data);
}

// Pop element from stack
void pop(struct node **top)
{
    struct node *temp;

    if(*top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    temp = *top;

    printf("%d popped from stack.\n", temp->data);

    *top = (*top)->next;

    free(temp);
}

// Peek top element
void peek(struct node *top)
{
    if(top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

// Display stack
void display(struct node *top)
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    temp = top;

    printf("Stack elements: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct node *top = NULL;

    int choice;
    int data;

    do
    {
        printf("\n--- STACK USING LINKED LIST ---\n");
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

                push(&top, data);
                break;

            case 2:
                pop(&top);
                break;

            case 3:
                peek(top);
                break;

            case 4:
                display(top);
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

