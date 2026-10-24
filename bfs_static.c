#include <stdio.h>

int main()
{
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int visited[5] = {0};
    int queue[5];

    int front = 0;
    int rear = 0;
    int i, node;

    queue[rear] = 0;
    rear++;
    visited[0] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        node = queue[front];
        front++;

        printf("%d ", node);

        for (i = 0; i < 5; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }

    return 0;
}
