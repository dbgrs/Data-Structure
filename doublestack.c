#include <stdio.h>

#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

//Push1
void push1(int value)
{
    if (top1 + 1 == top2)
    {
        printf("\nStack Overflow!");
        return;
    }

    top1++;
    stack[top1] = value;

    printf("\n%d pushed into Stack 1.", value);
}

//Push2
void push2(int value)
{
    if (top1 + 1 == top2)
    {
        printf("\nStack Overflow!");
        return;
    }

    top2--;
    stack[top2] = value;

    printf("\n%d pushed into Stack 2.", value);
}

//Pop1
void pop1(void)
{
    if (top1 == -1)
    {
        printf("\nStack 1 Underflow!");
        return;
    }

    printf("\n%d popped from Stack 1.", stack[top1]);
    top1--;
}

//Pop2
void pop2(void)
{
    if (top2 == MAX)
    {
        printf("\nStack 2 Underflow!");
        return;
    }

    printf("\n%d popped from Stack 2.", stack[top2]);
    top2++;
}

//Display1
void display1(void)
{
    int i;

    if (top1 == -1)
    {
        printf("\nStack 1 is empty.");
        return;
    }

    printf("\n\nStack 1:");

    for (i = top1; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
}

//Display2
void display2(void)
{
    int i;

    if (top2 == MAX)
    {
        printf("\nStack 2 is empty.");
        return;
    }

    printf("\n\nStack 2:");

    for (i = top2; i < MAX; i++)
    {
        printf("\n%d", stack[i]);
    }
}

// Main
int main(void)
{
    int choice;
    int value;

    while (1)
    {
        printf("\n--- DOUBLE STACK MENU ---");
        printf("\n1. Push Stack 1");
        printf("\n2. Push Stack 2");
        printf("\n3. Pop Stack 1");
        printf("\n4. Pop Stack 2");
        printf("\n5. Display Stack 1");
        printf("\n6. Display Stack 2");
        printf("\n7. Exit");


        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                push1(value);
                break;

            case 2:
                printf("\nEnter value: ");
                scanf("%d", &value);
                push2(value);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display1();
                break;

            case 6:
                display2();
                break;

            case 7:
                return 0;

            default:
                printf("\nInvalid choice! Please enter 1 to 7.");
        }
    }

    return 0;
}

