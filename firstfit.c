#include<stdio.h>

int main() {
    static int block_arr[10], file_arr[10];
    int fragments[10], blocks[10], files[10];
    int m, n, number_of_blocks, number_of_files, temp;

    printf("Enter the total number of Blocks:\t ");
    scanf("%d", &number_of_blocks);
    printf("\nEnter the total number of files:\t");
    scanf("%d", &number_of_files);

    printf("\nEnter the size of the blocks: ");
    for (m = 0; m < number_of_blocks; m++) {
        printf("Block No.[%d]:\t", m + 1);
        scanf("%d", &blocks[m]);
    }

    printf("\nEnter the size of the files: ");
    for (n = 0; n < number_of_files; n++) {
        printf("File no.[%d]:\t", n + 1);
        scanf("%d", &files[n]);  // Corrected index to 'n'
    }

    for (m = 0; m < number_of_files; m++) {
        for (n = 0; n < number_of_blocks; n++) {
            if (block_arr[n] != 1) {
                temp = blocks[n] - files[m];
                if (temp >= 0) {
                    file_arr[m] = n;
                    break;
                }
            }
        }
        fragments[m] = temp;
        block_arr[file_arr[m]] = 1;
    }

    printf("\nFile Number\tBlock Number\tFile Size\tBlock Size\tFragment");
    for (m = 0; m < number_of_files; m++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m + 1, file_arr[m] + 1, files[m], blocks[file_arr[m]], fragments[m]);
    }
    printf("\n");
    return 0;
}
