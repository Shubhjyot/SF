#include <stdio.h>

void fifo(int page_reference_string[], int n, int num_frames) {
    int page_frames[num_frames];
    int page_faults = 0;
    int hits = 0;
    int frame_index = 0;

    for (int i = 0; i < num_frames; ++i) {
        page_frames[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        int page = page_reference_string[i];
        int page_found = 0;

        for (int j = 0; j < num_frames; ++j) {
            if (page_frames[j] == page) {
                printf("Page %d is already in memory(hit)\n", page);
                hits++;
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            printf("Page Fault: ");
            printf("%d replaced by %d\n", page_frames[frame_index], page);
            page_frames[frame_index] = page;
            page_faults++;

            frame_index = (frame_index + 1) % num_frames;

            printf("Current page frames: ");
            for (int j = 0; j < num_frames; ++j) {
                printf("%d ", page_frames[j]); // Fix: Corrected the array index here
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Hit Ratio: %.2f%%\n", ((float)hits / n) * 100);
}

int main() {
    int n, num_frames;

    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &n);
    
    int page_reference_string[n]; // Fix: Corrected the array declaration

    printf("Enter the reference string (comma separated): ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &page_reference_string[i]);
    }

    printf("Enter the number of page frames: ");
    scanf("%d", &num_frames);

    fifo(page_reference_string, n, num_frames);
    return 0;
}
