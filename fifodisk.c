#include <stdio.h>
#include <stdlib.h>

void fifo(int request_queue[], int size, int head_position) {
    int seek_sequence[size + 1];
    int total_seek_time = 0;
    int head = head_position;

    seek_sequence[0] = head; // Initialize the first element in the seek sequence array

    for (int i = 0; i < size; i++) {
        total_seek_time += abs(head - request_queue[i]);
        head = request_queue[i];
        seek_sequence[i + 1] = head; // Store the new head position in the seek sequence array
    }

    printf("Seek Sequence: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", seek_sequence[i]);
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int head, n, i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the disk requests:");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    fifo(arr, n, head);

    free(arr);
    return 0;
}
