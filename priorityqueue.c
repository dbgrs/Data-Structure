
#include <stdio.h>

#define MAX 10

int queue[MAX];
int priority[MAX];

int front = -1;
int rear = -1;

// Add process to priority queue
void enqueue(int process, int p)
{
    int i;

    if (rear == MAX - 1)
    {
        printf("Priority Queue is full!\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        i = rear + 1;

        // Higher priority number comes first
        while (i > front && priority[i - 1] < p)
        {
            queue[i] = queue[i - 1];
            priority[i] = priority[i - 1];
            i--;
        }

        queue[i] = process;
        priority[i] = p;

        rear++;

        printf("Process P%d added to priority queue.\n", process);
    }
}

// Remove highest-priority process
void dequeue()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Priority Queue is empty!\n");
    }
    else
    {
        printf("Process P%d with priority %d removed.\n",
               queue[front], priority[front]);

        for (i = front; i < rear; i++)
        {
            queue[i] = queue[i + 1];
            priority[i] = priority[i + 1];
        }

        rear--;

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
        printf("Priority Queue is empty!\n");
    }
    else
    {
        printf("\nProcesses in priority queue:\n");
        printf("Process\tPriority\n");

        for (i = front; i <= rear; i++)
        {
            printf("P%d\t%d\n", queue[i], priority[i]);
        }
    }
}

int main()
{
    int choice;
    int process;
    int p;

    while (1)
    {
        printf("\n--- PRIORITY QUEUE ---\n");
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

            printf("Enter priority: ");
            scanf("%d", &p);

            enqueue(process, p);
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
