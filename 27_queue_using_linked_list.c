#include <stdio.h>
#include <stdlib.h>
// Create node
struct node
{
    int data;
    struct node *next;
};
// Insert element into queue
void enqueue(struct node **front, struct node **rear, int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // If queue is empty
    if(*front == NULL)
    {
        *front = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("%d inserted into queue.\n", data);
}

// Delete element from queue
void dequeue(struct node **front, struct node **rear)
{
    struct node *temp;
    // Check if queue is empty
    if(*front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    temp = *front;
    printf("%d deleted from queue.\n", temp->data);
    *front = (*front)->next;
    // If queue becomes empty
    if(*front == NULL)
    {
        *rear = NULL;
    }
    free(temp);
}

// Display queue
void display(struct node *front)
{
    struct node *temp;
    if(front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    temp = front;
    printf("Queue elements: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
        printf("\n--- QUEUE USING LINKED LIST ---\n");
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

