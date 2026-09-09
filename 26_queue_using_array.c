#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

// Insert element into queue
void enqueue(int data)
{
    if(rear == MAX - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d inserted into queue.\n", data);
    }
}

// Delete element from queue
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("%d deleted from queue.\n", queue[front]);
        front++;
        if(front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

// Display queue
void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
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
        printf("\n--- QUEUE USING ARRAY ---\n");
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

