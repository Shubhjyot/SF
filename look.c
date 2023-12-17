#include <stdio.h>
#include <stdlib.h>

void LOOK(int arr[], int head, char direction, int size) {
    int distance = 0;
    int current, previous = head;  // Initialize 'previous' with the initial head position
    int i;
    int total_distance = 0;

    int left = 0, right = 0;

    // Sorting
    for (i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Head position
    for (i = 0; i < size; i++) {
        if (arr[i] > head) {
            left = i - 1;
            right = i;
            break;
        }
    }

    // Left
    for (i = left; i >= 0; i--) {
        current = arr[i];
        distance = abs(current - previous);
        total_distance += distance;
        previous = current;
    }

    // Right
    for (i = right; i < size; i++) {
        current = arr[i];
        distance = abs(current - previous);
        total_distance += distance;
        previous = current;
    }

    printf("\nSeek Sequence: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTotal Head Movement: %d\n", total_distance);
}

int main() {
    int head, n, i;
    char direction;

    printf("\nEnter the number of disk requests: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the initial position of head: ");
    scanf("%d", &head);

    printf("\nEnter the direction(L/R): ");
    scanf(" %c", &direction);

    LOOK(arr, head, direction, n);

    free(arr);
    return 0;
}
