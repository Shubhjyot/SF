#include<stdio.h>

// Function to perform SJF scheduling
void sjfScheduling(int processes[], int n, int bt[]) {
    // Array to store waiting time for each process
    int wt[n];

    // Array to store turnaround time for each process
    int tat[n];

    // Copy burst times to a temporary array
    int temp_bt[n];
    for (int i = 0; i < n; i++)
        temp_bt[i] = bt[i];

    // Sort processes based on burst time (non-decreasing order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp_bt[j] > temp_bt[j + 1]) {
                // Swap burst times
                int temp = temp_bt[j];
                temp_bt[j] = temp_bt[j + 1];
                temp_bt[j + 1] = temp;

                // Swap process IDs
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time for each process
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = temp_bt[i - 1] + wt[i - 1];

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = temp_bt[i] + wt[i];

    // Display the table
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);

    // Calculate and display average waiting time and average turn-around time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage waiting time = %.2f\n", total_wt / n);
    printf("Average turn-around time = %.2f\n", total_tat / n);
}

int main() {
    // Number of processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Array to store burst time of processes
    int bt[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Array to store process IDs
    int processes[n];
    for (int i = 0; i < n; i++)
        processes[i] = i + 1;

    // Call function to perform SJF scheduling
    sjfScheduling(processes, n, bt);

    return 0;
}
