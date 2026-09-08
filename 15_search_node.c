
#include <stdio.h>
#include <stdlib.h>

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

// Search for a node and return its position
int search_node(struct node *head, int data)
{
    struct node *temp = head;
    int position = 1;

    while(temp != NULL)
    {
        if(temp->data == data)
        {
            return position;
        }

        temp = temp->next;
        position++;
    }

    return -1;
}

int main()
{
    struct node *head = NULL;

    int n, data, i;
    int choice;
    int searchData;
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
        printf("2. Display linked list\n");
        printf("3. Search node\n");
        printf("4. Exit\n");

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
                printf("Linked list: ");
                display(head);
                break;

            case 3:
                printf("Enter data to search: ");
                scanf("%d", &searchData);

                position = search_node(head, searchData);

                if(position != -1)
                {
                    printf("Node found: %d\n", searchData);
                    printf("Position: %d\n", position);
                }
                else
                {
                    printf("Node not found.\n");
                }

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

