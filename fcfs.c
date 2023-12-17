#include<stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    // Waiting time for the first process is always 0
    wt[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];
}

// Function to calculate turn-around time of each process
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Turn-around time is the sum of waiting time and burst time for each process
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to display the table
void displayTable(int processes[], int n, int bt[], int wt[], int tat[]) {
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn-Around Time\n");

    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
}

// Function to calculate average time
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    // Find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // Find turn-around time of all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display the table
    displayTable(processes, n, bt, wt, tat);

    // Calculate the average waiting time and average turn-around time
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

    // Call function to calculate average waiting time and turn-around time
    findAverageTime(processes, n, bt);

    return 0;
}
