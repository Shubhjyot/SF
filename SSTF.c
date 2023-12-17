// #include <stdio.h>
// #include <stdlib.h>

// void SSTF(int arr[], int size, int head) {
//     int shortest_distance, current_distance, seek_count = 0;

//     while (1) {
//         shortest_distance = 99999;
//         int done = 0;
//         int new_requests[size];

//         // Check all pending requests
//         for (int i = 0; i < size; i++) {
//             if (arr[i] != -1) {
//                 current_distance = abs(arr[i] - head);
//                 if (current_distance < shortest_distance) {
//                     shortest_distance = current_distance;
//                     seek_count += current_distance;
//                     head = arr[i];
//                     arr[i] = -1;
//                     done = 1;
//                 }
//             }
//         }

//         if (done == 0)
//             break;
//     }

//     printf("Total number of seek operations are %d\n", seek_count);
// }

// int main() {
//     int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int head = 50;

//     SSTF(arr, size, head);

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//finding shortest seek time wala index
int findsstf(int arr[],int head,int visited[],int size){
    int minDistance=INT_MAX;
    int index=-1;

    for(int i=0;i<size;i++){
        if(!visited[i]){
            int distance=abs(arr[i]-head);
            if(distance<minDistance){
                minDistance=distance;
                index=i;
            }
        }
    }
    return index;
}

//performing sstf
void sstf(int arr[],int head,int size){
    int total_distance=0;
    int* seek_sequence=(int*)malloc(size*sizeof(int));
    int* visited=(int*)calloc(size,sizeof(int));

    if(seek_sequence==NULL || visited==NULL){
        printf("\nMemory allocation failed.");
        exit(EXIT_FAILURE);
    }

    int current=head;
    for(int i=0;i<size;i++){
        int index=findsstf(arr,current,visited,size);
        visited[index]=1;//marking visited
        seek_sequence[i]=arr[index];
        total_distance+=abs(arr[index]-current);
        current=arr[index];
    }

    printf("\nSeek Sequence: ");
    for(int i=0;i<size;i++){
        printf("%d ",seek_sequence[i]);
    }

    printf("\nTotal Head Movement: %d",total_distance);

    free(seek_sequence);
    free(visited);
}

int main() {
    int head, n, i;

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

    sstf(arr, head, n);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}