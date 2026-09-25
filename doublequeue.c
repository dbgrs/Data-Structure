#include <stdio.h>

#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int value, choice;

    printf("\n1. Insert at Front");
    printf("\n2. Insert at Rear");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%d", &value);

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is Full!\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (choice == 1)
    {
        if (front == 0)
            front = MAX - 1;
        else
            front--;
    }
    else if (choice == 2)
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear++;
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    deque[front] = value;

    if (choice == 2)
        deque[rear] = value;

    printf("Element inserted successfully.\n");
}

void deleteElement()
{
    int choice;

    if (front == -1)
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("\n1. Delete from Front");
    printf("\n2. Delete from Rear");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Deleted element = %d\n", deque[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    else if (choice == 2)
    {
        printf("Deleted element = %d\n", deque[rear]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
    else
    {
        printf("Invalid choice!\n");
    }
}

void modify()
{
    int position, value;
    int i, index;

    if (front == -1)
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Enter position to modify: ");
    scanf("%d", &position);

    if (position < 1 || position > MAX)
    {
        printf("Invalid position!\n");
        return;
    }

    index = front;

    for (i = 1; i < position; i++)
    {
        if (index == rear)
        {
            printf("Position does not exist!\n");
            return;
        }

        index++;

        if (index == MAX)
            index = 0;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    deque[index] = value;

    printf("Element modified successfully.\n");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("\nDeque elements are:\n");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i++;

        if (i == MAX)
            i = 0;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== DOUBLE ENDED QUEUE =====");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Modify");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
