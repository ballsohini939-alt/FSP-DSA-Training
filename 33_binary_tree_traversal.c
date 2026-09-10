#include <stdio.h>
#include <stdlib.h>
// Structure for binary tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node* createNode(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Create binary tree
struct node* createTree()
{
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if(data == -1)
    {
        return NULL;
    }
    struct node *newNode = createNode(data);
    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();
    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();
    return newNode;
}

// Preorder Traversal
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *root = NULL;
    int choice;
    do
    {
        printf("\n--- BINARY TREE MENU ---\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nCreate Binary Tree:\n");
                root = createTree();
                break;
            case 2:
                if(root == NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root == NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root == NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}

