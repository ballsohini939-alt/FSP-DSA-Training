
#include <stdio.h>
#include <stdlib.h>

// Create a doubly linked list node

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Create a new node at the end
void create_newNode(struct node **head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete node from beginning
void delete_beginning(struct node **head)
{
    struct node *temp;

    if(*head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    if(*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(temp);

    printf("Node deleted from beginning.\n");
}

// Delete node from end
void delete_end(struct node **head)
{
    struct node *temp;

    if(*head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    temp = *head;

    // Move to the last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // If there is only one node
    if(temp->prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        temp->prev->next = NULL;
    }

    free(temp);

    printf("Node deleted from end.\n");
}

// Delete node from a specific position
void delete_position(struct node **head, int position)
{
    struct node *temp;
    int i;

    if(*head == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    if(position == 1)
    {
        delete_beginning(head);
        return;
    }

    temp = *head;

    // Move to the specified position
    for(i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    // Connect previous node to next node
    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    // Connect next node to previous node
    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted from position %d.\n", position);
}

// Display linked list
void display(struct node *head)
{
    struct node *temp = head;

    if(temp == NULL)
    {
        printf("Doubly linked list is empty!\n");
        return;
    }

    printf("Doubly linked list: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

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

        create_newNode(&head, data);
    }

    do
    {
        printf("\n1. Create new node\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Delete from specific position\n");
        printf("5. Display linked list\n");
        printf("6. Exit\n");

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
                delete_beginning(&head);
                break;

            case 3:
                delete_end(&head);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);

                delete_position(&head, position);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 6);

    return 0;
}

