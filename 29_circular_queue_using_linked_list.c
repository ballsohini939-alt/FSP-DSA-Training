#include <stdio.h>
#include <stdlib.h>

// Circular queue node
struct node
{
    int data;
    struct node *next;
};

// Insert element into circular queue
void enqueue(struct node **front, struct node **rear, int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    // If queue is empty
    if(*front == NULL)
    {
        *front = newNode;
        *rear = newNode;
        newNode->next = *front;
    }
    else
    {
        newNode->next = *front;
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d inserted into circular queue.\n", data);
}

// Delete element from circular queue
void dequeue(struct node **front, struct node **rear)
{
    struct node *temp;
    // Check if queue is empty
    if(*front == NULL)
    {
        printf("Circular queue is empty!\n");
        return;
    }
    // If there is only one node
    if(*front == *rear)
    {
        printf("%d deleted from circular queue.\n", (*front)->data);
        free(*front);
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        temp = *front;
        printf("%d deleted from circular queue.\n", temp->data);
        *front = (*front)->next;
        (*rear)->next = *front;
        free(temp);
    }
}

// Display circular queue
void display(struct node *front)
{
    struct node *temp;
    if(front == NULL)
    {
        printf("Circular queue is empty!\n");
        return;
    }
    temp = front;
    printf("Circular queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
    printf("\n");
}

int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;

    int choice;
    int data;

    do
    {
        printf("\n--- CIRCULAR QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                enqueue(&front, &rear, data);
                break;

            case 2:
                dequeue(&front, &rear);
                break;

            case 3:
                display(front);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}

