#include<stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int num;

    printf("\nEnter number : ");
    scanf("%d", &num);

    if((front == 0 && rear == MAX - 1) || (rear + 1 == front))
    {
        printf("\nOverflow");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if(rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}


void delete()
{
    int val;

    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow");
        return;
    }

    val = queue[front];

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    printf("\nDeleted : %d", val);
}


void modify()
{
    int pos, value, i;

    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nEnter position : ");
    scanf("%d", &pos);

    printf("\nEnter new value : ");
    scanf("%d", &value);

    if(pos >= front && pos < MAX)
    {
       queue[pos] = value;
       printf("\nElement modified successfully");
    }
    else if(pos >= 0 && pos <= rear)
    {
       queue[pos] = value;
       printf("\nElement modified successfully");
    }

}


void display()
{
    int i;

	printf("\n Circular Queue Elements : ");

    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
        return;
    }

    if(front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("\n %d", queue[i]);
        }
    }
    else
    {
        for(i = front; i < MAX; i++)
        {
            printf("\n %d", queue[i]);
        }

        for(i = 0; i <= rear; i++)
        {
            printf("\n %d", queue[i]);
        }
    }
}



int main()
{

	int choice;

	do
	{

		
		printf("\n --- Menu Circular Queue ---");
		printf("\n 1. Insert");
		printf("\n 2. Delete");
		printf("\n 3. Display");
		printf("\n 4. Modify");
		printf("\n 5. Eixt");

		printf("\n Enter your choice :");
		scanf("%d", &choice);

		switch(choice)
		{	
			case 1:
				insert();
				break;

			case 2:
				delete();
				break;

			case 3:
				display();
				break;

			case 4:
				modify();
				break;

			case 5:
				return 0;

			default:
				printf("\n Invalid operation");
				break;

		}

	}while(choice != 5);

	return 0;
}
