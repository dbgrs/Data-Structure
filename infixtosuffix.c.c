#include <stdio.h>

char stack[50];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x;
    x = stack[top];
    top--;
    return x;
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    if (x == '^')
        return 3;

    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i = 0, j = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        x = infix[i];

        if ((x >= 'A' && x <= 'Z') ||
            (x >= 'a' && x <= 'z') ||
            (x >= '0' && x <= '9'))
        {
            postfix[j] = x;
            j++;
        }

        else if (x == '(')
        {
            push(x);
        }

        else if (x == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            pop();   
        }


        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(x))
            {
                postfix[j] = pop();
                j++;
            }

            push(x);
        }

        i++;
    }


    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression = %s ", postfix);

    return 0;
}
