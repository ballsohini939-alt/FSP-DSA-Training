#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

// Insert element into circular queue
void enqueue(int data)
{
    // Check if queue is full
    if((rear + 1) % MAX == front)
    {
        printf("Circular Queue is full!\n");
        return;
    }
    // First element
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = data;
    printf("%d inserted into queue.\n", data);
}

// Delete element from circular queue
void dequeue()
{
    // Check if queue is empty
    if(front == -1)
    {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("%d deleted from queue.\n", queue[front]);

    // If only one element exists
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Display circular queue
void display()
{
    int i;
    if(front == -1)
    {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue elements: ");
    i = front;
    while(1)
    {
        printf("%d ", queue[i]);
        if(i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    int choice;
    int data;
    do
    {
        printf("\n--- CIRCULAR QUEUE USING ARRAY ---\n");
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
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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

