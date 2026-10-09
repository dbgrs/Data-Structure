#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push
void Push()
{
	int value;
	if(top==MAX-1)
	{
		printf("\n Stack Overflow!");
	}

	printf("\n Enter Value : ");
	scanf("%d", &value);

	top++;
	stack[top]=value;

	printf("%d", "inserted successfully!", value);

}

// Pop

void Pop()
{
	
	if(top==-1)
	{
		printf("\n Stack is underflow!");
	}

	printf("\n Deleted elements : %d", stack[top]);
	top--;
}

// Display

void Display()
{
	int i;

	if(top==-1)
	{
		printf("\n Stack is empty!");
	}

	printf("\n Stack Elements are : \n");
	
	for(i=top; i>=0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

// Peek

void Peek()
{
	if(top==-1)
	{
		printf("\n Stack underflow!");
	}

	printf("\n Top element : %d", stack[top]);
	printf("\n");

}

// Modify

void Modify()
{

	int pos, value;

	printf("\n Enter postition which value you have to modified :");
	scanf("%d", &pos);

	printf("\n Enter new value : ");
	scanf("%d", &value);

	if(top==-1)
	{
		printf("\n Stack empty!");
	}
	
	if(pos < 1 || pos > top+1)
	{
		printf("\n Invalid postition");
	}
	

	stack[pos - 1] = value;


}

void main()
{
	int choice;

	do
	{
		printf("\n --- Stack Menu ---");
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Display");
		printf("\n 4. Peek");
		printf("\n 5. Modify");
		printf("\n 6. Exit");

		printf("\n Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				Push();
				break;
			
			case 2:
				Pop();
				break;

			case 3:
				Display();
				break;

			case 4:
				Peek();
				break;

			case 5:
				Modify();
				break;
		}

	}while(choice!=6);
}
