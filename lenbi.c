#include <stdio.h>

int main()
{
    int a[100], n, i, key;
    int choice, found, low, high, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (choice == 1)
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (a[i] == key)
            {
                printf("Element found at position %d\n", i + 1);
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            printf("Element not found\n");
        }
    }
    else if (choice == 2)
    {
        low = 0;
        high = n - 1;
        found = 0;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (a[mid] == key)
            {
                printf("Element found at position %d\n", mid + 1);
                found = 1;
                break;
            }
            else if (a[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (found == 0)
        {
            printf("Element not found\n");
        }
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}
