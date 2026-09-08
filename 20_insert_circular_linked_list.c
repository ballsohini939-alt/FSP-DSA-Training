
#include <stdio.h>
#include <stdlib.h>

// Circular linked list node
struct node
{
    int data;
    struct node *next;
};

// Create a new node
struct node* create_newNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert node at beginning
void insert_beginning(struct node **head, int data)
{
    struct node *newNode = create_newNode(data);
    struct node *temp;

    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        temp = *head;

        // Move to the last node
        while(temp->next != *head)
        {
            temp = temp->next;
        }

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Insert node at end
void insert_end(struct node **head, int data)
{
    struct node *newNode = create_newNode(data);
    struct node *temp;

    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        temp = *head;

        // Move to the last node
        while(temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head;
    }
}

// Insert node at a specific position
void insert_position(struct node **head, int data, int position)
{
    struct node *newNode;
    struct node *temp;
    int i;

    if(position == 1)
    {
        insert_beginning(head, data);
        return;
    }

    if(*head == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    newNode = create_newNode(data);
    temp = *head;

    // Move to the node before the required position
    for(i = 1; i < position - 1; i++)
    {
        temp = temp->next;

        if(temp == *head)
        {
            printf("Invalid position!\n");
            free(newNode);
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
    int position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        insert_end(&head, data);
    }

    do
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Display circular linked list\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                insert_beginning(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);

                insert_end(&head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                insert_position(&head, data, position);
                break;

            case 4:
                printf("Circular linked list: ");
                display(head);
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
