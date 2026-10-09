
#include <stdio.h>

int main() {
    int process[10], remaining[10];
    int n, i, j, temp;
    int completed = 0;
    int timeSlice = 2;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        process[i] = i + 1;

        printf("Enter execution time for P%d: ", i + 1);
        scanf("%d", &remaining[i]);
    }

    printf("\nProcess Queue Execution:\n");

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (remaining[i] > timeSlice) {
                    printf("P%d executes for 2 seconds\n",
                           process[i]);

                    remaining[i] -= timeSlice;
                } else {
                    printf("P%d executes for %d seconds\n",
                           process[i], remaining[i]);

                    remaining[i] = 0;
                    printf("P%d completed\n", process[i]);
                    completed++;
                }
            }
        }
    }

    printf("\nAll processes completed!\n");

    return 0;
}
