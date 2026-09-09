#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = ch;
    }
}
char pop()
{
    if(top == -1)
    {
        return '\0';
    }

    return stack[top--];
}
char peek()
{
    if(top == -1)
    {
        return '\0';
    }

    return stack[top];
}
int precedence(char ch)
{
    if(ch == '^')
        return 3;

    if(ch == '*' || ch == '/')
        return 2;

    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}
int isOperator(char ch)
{
    if(ch == '+' || ch == '-' ||
       ch == '*' || ch == '/' ||
       ch == '^')
    {
        return 1;
    }

    return 0;
}
/* Infix to Postfix */
void infixToPostfix(char infix[], char postfix[])
{
    int i;
    int j = 0;
    char ch;
    top = -1;
    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if(ch == ' ')
        {
            continue;
        }
        if(isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(top != -1 && peek() != '(')
            {
                postfix[j] = pop();
                j++;
            }
            if(top != -1 && peek() == '(')
            {
                pop();
            }
        }
        else if(isOperator(ch))
        {
            while(top != -1 &&
                  peek() != '(' &&
                  precedence(peek()) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }
    }
    while(top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}
/* Reverse a string */
void reverse(char str[])
{
    int i;
    int j;
    char temp;
    i = 0;
    j = strlen(str) - 1;
    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}
/* Infix to Prefix */
void infixToPrefix(char infix[], char prefix[])
{
    char reversed[MAX];
    char postfix[MAX];
    int i;
    strcpy(reversed, infix);
    reverse(reversed);
    /* Change '(' to ')' and ')' to '(' */
    for(i = 0; reversed[i] != '\0'; i++)
    {
        if(reversed[i] == '(')
        {
            reversed[i] = ')';
        }
        else if(reversed[i] == ')')
        {
            reversed[i] = '(';
        }
    }
    infixToPostfix(reversed, postfix);
    strcpy(prefix, postfix);
    reverse(prefix);
}
int main()
{
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);
    printf("Postfix expression: %s\n", postfix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
