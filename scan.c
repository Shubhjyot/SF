#include <stdio.h>
#include <stdlib.h>

void scan(int arr[], int head, char direction, int size) {
    int distance = 0;
    int current, i;
    int total_distance = 0;
    int* seek_sequence = (int*)malloc(size * sizeof(int)); // Dynamically allocate memory

    // Check for allocation failure
    if (seek_sequence == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

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

    // Find head in sorted array
    for (i = 0; i < size; i++) {
        if (arr[i] > head) {
            break;
        }
    }

    // Move left
    if (direction == 'L') {
        head = i;

        for (i = head - 1; i >= 0; i--) {
            current = arr[i];
            distance = abs(current - head);
            total_distance += distance;
            head = current;
            seek_sequence[i] = current; // Fix the index here
        }

        // Move right from the leftmost position to the rightmost
        for (i = head + 1; i < size; i++) {
            current = arr[i];
            distance = abs(current - head);
            total_distance += distance;
            head = current;
            seek_sequence[i] = current; // Fix the index here
        }
    }

    // Move right
    else {
        head = i - 1;

        // Move right from the rightmost position to the leftmost
        for (i = head + 1; i < size; i++) {
            current = arr[i];
            distance = abs(current - head);
            total_distance += distance;
            head = current;
            seek_sequence[i] = current; // Fix the index here
        }

        // Move left from the leftmost position to the rightmost
        for (i = head - 1; i >= 0; i--) {
            current = arr[i];
            distance = abs(current - head);
            total_distance += distance;
            head = current;
            seek_sequence[i] = current; // Fix the index here
        }
    }

    printf("Seek Sequence:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", seek_sequence[i]);
    }

    printf("\nTotal Head Movement: %d\n", total_distance);

    // Free dynamically allocated memory
    free(seek_sequence);
}

int main() {
    int head, n, i;
    char direction;

    printf("\nEnter the number of disk requests: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    
    // Check for allocation failure
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    printf("\nEnter the disk requests:");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the initial position of the head: ");
    scanf("%d", &head);

    printf("\nEnter the direction (L/R): ");
    scanf(" %c", &direction);

    scan(arr, head, direction, n);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
