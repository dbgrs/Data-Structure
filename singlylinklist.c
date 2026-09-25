#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node
void insert()
{
    struct Node *newNode;
    struct Node *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

// Delete a node
void deleteNode()
{
    struct Node *temp;
    struct Node *prev;
    int value;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    // If first node contains the value
    if (temp->data == value)
    {
        head = temp->next;
        free(temp);

        printf("Node deleted successfully.\n");
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found.\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);

        printf("Node deleted successfully.\n");
    }
}

// Modify a node
void modify()
{
    struct Node *temp;
    int oldValue;
    int newValue;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to modify: ");
    scanf("%d", &oldValue);

    temp = head;

    while (temp != NULL && temp->data != oldValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found.\n");
    }
    else
    {
        printf("Enter new value: ");
        scanf("%d", &newValue);

        temp->data = newValue;

        printf("Node modified successfully.\n");
    }
}

// Display the list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            deleteNode();
        }
        else if (choice == 3)
        {
            modify();
        }
        else if (choice == 4)
        {
            display();
        }
        else if (choice == 5)
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
