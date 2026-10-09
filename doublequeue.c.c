#include<stdio.h>

#define MAX 10

int dequeue[MAX];
int front=-1, rear=-1;

void Queue1(int value)
{
	if((front == 0 && rear == MAX -1) || front == rear + 1)
	{
		printf("\n Dequeue is Overflow");
		return;
	}

	if(front == -1)
	{
		front = rear = 0;
	}
	else if(front == 0)
	{
		front = MAX -1;
	}
	else
	{
		front--;
	}

	dequeue[front] = value;
}

void Queue2(int value)
{
	if((front == 0 && rear == MAX -1 || front == rear + 1))
	{
		printf("\nDequeue is Overflow");
		return;
	}

	if(front == -1)
	{
		front = rear = 0;
	}
	else if(rear == MAX -1)
	{
		rear = 0;
	}
	else
	{
		rear ++;
	}

	dequeue[rear] = value;

}

void Delete1()
{
	if(front==-1)
	{
		printf("\n Dequeue is Underflow");
		return;
	}

	printf("Deleted : %d\n", dequeue[front]);

	if(front == rear)
	{
		front = rear = -1;
	}
	else if(front == MAX -1)
	{
		front = 0;
	}
	else 
	{
		front++;
	}
}

void Delete2()
{
	if(front==-1)
	{
		printf("\n Dequeue is empty");
		return;
	}

	printf("\n Deleted : %d\n", dequeue[rear]);

	if(front==rear)
	{
		front=rear=-1;
	}
	else if(rear == 0)
	{
		rear = MAX -1;
	}
	else
	{
		rear--;
	}
}

void Display()
{	
	int i;

	if(front == -1)
	{
		printf("\n Dequeue is underflow");
		return;
	}

	printf("\n Dequeue : ");

	i = front;

	while(1)
	{
		printf("%d", dequeue[i]);

		if(i==rear)
		{
			break;
		}

		i=(i+1)%MAX;
	}

	printf("\n");
}

void modify()
{
    int pos, value, i, count;

    if (front == -1)
    {
        printf("\nDequeue is empty");
        return;
    }

    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > MAX)
    {
        printf("\nInvalid position");
        return;
    }

    i = front;
    count = 1;

    while (1)
    {
        if (count == pos)
        {
            printf("\nEnter new value : ");
            scanf("%d", &value);

            dequeue[i] = value;

            printf("\nValue modified successfully");
            return;
        }

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
        count++;
    }

    printf("\nInvalid position");
}



int main()
{
	int choice, value;

	while(1)
	{
		printf("\n --- Dequeue Menu ---");

		printf("\n 1. Insert Front");
		printf("\n 2. Insert Rear");
		printf("\n 3. Delete Front");
		printf("\n 4. Delete Rear");
		printf("\n 5. Display");
		printf("\n 6. Modify");
		printf("\n 7. Exit");

		printf("\n Enter Choice ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\n Enter value : ");
				scanf("%d", &value);
				Queue1(value);
				break;

			case 2:
				printf("\n Enter value : ");
				scanf("%d", &value);
				Queue2(value);
				break;

			case 3:
				Delete1();
				break;

			case 4:
				Delete2();
				break;

			case 5:
				Display();
				break;

			case 6:
				modify();
				break;
			
			case 7:
				return 0;


		}
	}

	return 0;
}