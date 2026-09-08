
#include <stdio.h>
#include <stdlib.h>

// Circular linked list node
struct node
{
    int data;
    struct node *next;
};

// Create a new node
void create_newNode(struct node **head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;

    // If the list is empty
    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct node *temp = *head;

        // Move to the last node
        while(temp->next != *head)
        {
            temp = temp->next;
        }

        // Insert new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Display circular linked list
void display(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    } while(temp != head);

    printf("\n");
}

int main()
{
    struct node *head = NULL;

    int n, data, i;
    int choice;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        create_newNode(&head, data);
    }

    do
    {
        printf("\n1. Create new node\n");
        printf("2. Display circular linked list\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);

                create_newNode(&head, data);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}

