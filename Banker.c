#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[10][10], max[10][10], need[10][10], avail[10];
    int finish[10] = {0}, safe[10];

    // Allocation
    printf("\nEnter Allocation matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Max
    printf("\nEnter Max matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Available
    printf("\nEnter Available resources:\n");
    for(int i=0; i<m; i++) {
        scanf("%d", &avail[i]);
    }

    // Need = Max - Allocation
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Safety Algorithm
    int count = 0;

    while(count < n) {
        int done = 0;

        for(int i=0; i<n; i++) {

            if(finish[i] == 0) {

                int canRun = 1;

                for(int j=0; j<m; j++) {
                    if(need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if(canRun == 1) {
                    for(int j=0; j<m; j++) {
                        avail[j] += alloc[i][j];
                    }

                    safe[count++] = i;
                    finish[i] = 1;
                    done = 1;
                }
            }
        }

        if(done == 0) {
            break;
        }
    }

    if(count == n) {
        printf("\nSystem is SAFE\nSequence: ");
        for(int i=0; i<n; i++) {
            printf("P%d ", safe[i]);
        }
    } else {
        printf("\nSystem is UNSAFE");
    }

    return 0;
}