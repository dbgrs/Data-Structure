#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted successfully.\n");
}

void delete()
{
    struct node *temp, *prev;
    int value;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    do {
        if (temp->data == value)
            break;

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->data != value) {
        printf("Value not found.\n");
        return;
    }

    if (temp->next == head && temp == head) {
        head = NULL;
    } else if (temp == head) {
        prev = head;

        while (prev->next != head) {
            prev = prev->next;
        }

        head = head->next;
        prev->next = head;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node deleted successfully.\n");
}

void modify()
{
    struct node *temp;
    int oldvalue, newvalue;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to modify: ");
    scanf("%d", &oldvalue);

    temp = head;

    do {
        if (temp->data == oldvalue) {
            printf("Enter new value: ");
            scanf("%d", &newvalue);

            temp->data = newvalue;
            printf("Node modified successfully.\n");
            return;
        }

        temp = temp->next;
    } while (temp != head);

    printf("Value not found.\n");
}

void display()
{
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular linked list: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main()
{
    int choice;

    do {
        printf("\n--- SINGLY CIRCULAR LINKED LIST ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
