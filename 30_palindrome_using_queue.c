#include <stdio.h>
#include <string.h>
#define MAX 100
char queue[MAX];
int front = 0;
int rear = -1;
void enqueue(char ch)
{
    rear++;
    queue[rear] = ch;
}
char dequeue()
{
    return queue[front++];
}
int main()
{
    char str[MAX];
    int i;
    int length;
    int palindrome = 1;
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    length = strlen(str);
    for(i = 0; i < length; i++)
    {
        enqueue(str[i]);
    }
    for(i = length - 1; i >= 0; i--)
    {
        if(dequeue() != str[i])
        {
            palindrome = 0;
            break;
        }
    }
    if(palindrome == 1)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}
