
#include <stdio.h>
#include <stdlib.h>
// Create a doubly linked list node and display it using two functions
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
// Create a new node
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
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        create_newNode(&head, data);
    }

    // Use switch case to display or create new node

    int choice;
    do
    {
        printf("\n1. Create new node\n");
        printf("2. Display linked list\n");
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

