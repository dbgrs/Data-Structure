#include <stdio.h>

int main()
{
    int n, e;
    int graph[5][5] = {0};
    int visited[5] = {0};
    int queue[5];

    int front = 0, rear = 0;
    int i, u, v, node, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);


    queue[rear] = start;
    rear++;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        node = queue[front];
        front++;

        printf("%d ", node);

        for (i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 &&
                visited[i] == 0)
            {
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }

    return 0;
}
