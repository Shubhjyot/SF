#include<stdio.h>

// Function to perform Non-Preemptive Priority scheduling
void priorityScheduling(int processes[], int n, int bt[], int priority[]) {
    // Array to store waiting time for each process
    int wt[n];

    // Array to store turnaround time for each process
    int tat[n];

    // Sort processes based on priority (non-decreasing order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap burst times
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                // Swap priorities
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time for each process
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Display the table
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], priority[i], wt[i], tat[i]);

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

    // Arrays to store burst time and priority of processes
    int bt[n], priority[n];

    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    // Array to store process IDs
    int processes[n];
    for (int i = 0; i < n; i++)
        processes[i] = i + 1;

    // Call function to perform Non-Preemptive Priority scheduling
    priorityScheduling(processes, n, bt, priority);

    return 0;
}
