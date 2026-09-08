
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
// Create a new node
struct node* create_newNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Insert node at beginning
void insert_beginning(struct node **head, int data)
{
    struct node *newNode = create_newNode(data);

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Insert node at end
void insert_end(struct node **head, int data)
{
    struct node *newNode = create_newNode(data);

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

// Insert node at a particular position
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

    newNode = create_newNode(data);
    temp = *head;

    for(i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Display linked list
void display(struct node *head)
{
    struct node *temp = head;

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

        insert_end(&head, data);
    }

    do
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at particular position\n");
        printf("4. Display linked list\n");
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
                printf("Doubly linked list: ");
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

