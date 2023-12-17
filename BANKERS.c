#include <stdio.h>
#include<stdlib.h>

void bankers_algorithm(int num_resources, int max_resources[], int num_processes,int allocation[][num_resources], int max_matrix[][num_resources]) {
    int available[num_resources];
    int need[num_processes][num_resources];
    int finish[num_processes];
    char safe_sequence[10][5]; // Assuming a maximum of 10 processes with a name like P[0]

    // Initialize available resources
    for (int i = 0; i < num_resources; i++) {
        available[i] = max_resources[i];
    }

    // Initialize need matrix
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = max_matrix[i][j] - allocation[i][j];
        }
        finish[i] = 0; // Initialize finish array
    }

    // Print initial state
    printf("Initial State:\n");
    printf("Available: ");
    for (int i = 0; i < num_resources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    // Banker's Algorithm
    int count = 0;
    while (count < num_processes) {
        int found = 0;
        for (int i = 0; i < num_processes; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < num_resources; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == num_resources) {
                    // Process can be allocated
                    printf("\nStep %d:\n", count + 1);
                    printf("Process P%d can be allocated.\n", i);
                    printf("Available resources after allocation: ");
                    for (int k = 0; k < num_resources; k++) {
                        available[k] += allocation[i][k];
                        printf("%d ", available[k]);
                    }
                    printf("\n");
                    finish[i] = 1;
                    sprintf(safe_sequence[count], "P%d", i); // Removed the square brackets
                    count++;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSystem is in an unsafe state.\n");
            return;
        }
    }

    // Print final safe sequence
    printf("\nFinal Safe Sequence: < ");
    for (int i = 0; i < num_processes; i++) {
        printf("%s ", safe_sequence[i]);
    }
    printf(">\n");
}

int main() {
    int num_resources;
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    int max_resources[num_resources];
    printf("Enter the max instances of each resource:\n");
    for (int i = 0; i < num_resources; i++) {
        printf("%c= ", 'a' + i);
        scanf("%d", &max_resources[i]);
    }

    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    int allocation[num_processes][num_resources];
    int max_matrix[num_processes][num_resources];

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the MAX matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max_matrix[i][j]);
        }
    }

    bankers_algorithm(num_resources, max_resources, num_processes, allocation, max_matrix);
    return 0;
}
