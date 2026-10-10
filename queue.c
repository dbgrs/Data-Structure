#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;


void Enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("\n Queue Overflow!.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("%d inserted successfully.\n", value);
}


void Dequeue()
{
    int value;

    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    value = queue[front];

    printf("%d deleted successfully.\n", value);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void modify()
{
    int position, newValue;

    if (front == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    };

    printf("\nEnter position to modify: ");
    scanf("%d", &position);

    if (position < 1 || position > (rear - front + 1))
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &newValue);

    queue[position - 1] = newValue;

    printf("Element modified successfully.\n");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue elements:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {

        printf("\n --- Queue Menu --- \n");
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
                Enqueue();
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
                break;

            default:
                printf("\n Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}
