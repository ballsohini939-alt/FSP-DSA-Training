#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Create a new node and insert at end
void create_newNode(struct node **head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

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
    }
}

// Delete from beginning
void delete_beginning(struct node **head)
{
    struct node *temp;

    if(*head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    free(temp);

    printf("Node deleted from beginning.\n");
}

// Delete from end
void delete_end(struct node **head)
{
    struct node *temp;
    struct node *prev;

    if(*head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    temp = *head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    printf("Node deleted from end.\n");
}

// Delete from specified position
void delete_position(struct node **head, int position)
{
    struct node *temp;
    struct node *prev;
    int i;

    if(*head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    if(position == 1)
    {
        delete_beginning(head);
        return;
    }

    temp = *head;

    for(i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted from position %d.\n", position);
}

// Display linked list
void display(struct node *head)
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Linked list: ");

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
        printf("4. Delete from specified position\n");
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