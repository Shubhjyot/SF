#include <stdio.h>
#include <stdlib.h>

void cscan(int arr[], int head, int size) {
    int distance = 0;
    int total_distance = 0;

    // Sorting
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Finding head in sorted
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] > head) {
            break;
        }
    }

    // Right
    for (; i < size; i++) {
        int current = arr[i];
        distance = abs(current - head);
        total_distance += distance;
        head = current;
    }

    // Move to the end of the disk (rightmost position)
    total_distance += (size - 1) - head;  // Corrected calculation
    head = size - 1;

    // Left
    for (i = size - 1; i >= 0; i--) {
        int current = arr[i];
        distance = abs(current - head);
        total_distance += distance;
        head = current;
    }

    printf("Seek Sequence: ");
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }

    printf("Total Head Movement: %d\n", total_distance);
}

int main() {
    int head, n, i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    cscan(arr, head, n);

    free(arr);

    return 0;
}
