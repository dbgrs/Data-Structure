#include <stdio.h>

#define MAX 10

int queue[MAX];
int priority[MAX];

int size = 0;

// Insert an element
void insert()
{
    int value, p;
    int i;

    if (size == MAX)
    {
        printf("Priority Queue is full!\n");
        return;
    }

    printf("Enter process number: ");
    scanf("%d", &value);

    printf("Enter priority: ");
    scanf("%d", &p);

    i = size;

    // Higher priority number comes first
    while (i > 0 && priority[i - 1] < p)
    {
        queue[i] = queue[i - 1];
        priority[i] = priority[i - 1];
        i--;
    }

    queue[i] = value;
    priority[i] = p;

    size++;

    printf("Process P%d inserted successfully.\n", value);
}

// Delete the highest-priority element
void delete()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Process P%d with priority %d removed.\n",
           queue[0], priority[0]);

    for (i = 0; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

// Display the queue
void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nProcess\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("P%d\t%d\n", queue[i], priority[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- PRIORITY QUEUE ---\n");
        printf("1. Insert Process\n");
        printf("2. Delete Process\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            delete();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            printf("Program ended.\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
