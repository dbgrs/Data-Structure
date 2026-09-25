#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

// Add process to queue
void enqueue(int process)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = process;

        printf("Process P%d added to queue.\n", process);
    }
}

// Remove process from queue
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Process P%d removed from queue.\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

// Display processes
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Processes in queue: ");

        for (i = front; i <= rear; i++)
        {
            printf("P%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;
    int process;

    while (1)
    {
        printf("\n--- PROCESS QUEUE ---\n");
        printf("1. Add Process\n");
        printf("2. Remove Process\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter process number: ");
            scanf("%d", &process);

            enqueue(process);
        }
        else if (choice == 2)
        {
            dequeue();
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
