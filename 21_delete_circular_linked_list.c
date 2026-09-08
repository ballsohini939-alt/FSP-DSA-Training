
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

    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct node *temp = *head;

        while(temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head;
    }
}

// Delete node from beginning
void delete_beginning(struct node **head)
{
    struct node *temp;
    struct node *last;

    if(*head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    // If there is only one node
    if((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        printf("Node deleted from beginning.\n");
        return;
    }

    temp = *head;
    last = *head;

    // Find the last node
    while(last->next != *head)
    {
        last = last->next;
    }

    *head = (*head)->next;
    last->next = *head;

    free(temp);

    printf("Node deleted from beginning.\n");
}

// Delete node from end
void delete_end(struct node **head)
{
    struct node *temp;
    struct node *previous;

    if(*head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    // If there is only one node
    if((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    temp = *head;

    // Move to the last node
    while(temp->next != *head)
    {
        temp = temp->next;
    }

    // Find the node before the last node
    previous = *head;

    while(previous->next != temp)
    {
        previous = previous->next;
    }

    previous->next = *head;

    free(temp);

    printf("Node deleted from end.\n");
}

// Delete node from a specific position
void delete_position(struct node **head, int position)
{
    struct node *temp;
    struct node *previous;
    int i;

    if(*head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return;
    }

    if(position <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    // Delete first node
    if(position == 1)
    {
        delete_beginning(head);
        return;
    }

    temp = *head;

    // Move to the node at the required position
    for(i = 1; i < position; i++)
    {
        temp = temp->next;

        // We have reached the head again
        if(temp == *head)
        {
            printf("Invalid position!\n");
            return;
        }
    }

    // Find the previous node
    previous = *head;

    while(previous->next != temp)
    {
        previous = previous->next;
    }

    previous->next = temp->next;

    free(temp);

    printf("Node deleted from position %d.\n", position);
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

    printf("Circular linked list: ");

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

        create_newNode(&head, data);
    }

    do
    {
        printf("\n1. Create new node\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Delete from specific position\n");
        printf("5. Display circular linked list\n");
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

