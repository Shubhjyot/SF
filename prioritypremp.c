#include <stdio.h>

// Function to perform Preemptive Priority scheduling
void preemptivePriorityScheduling(int processes[], int n, int bt[], int priority[]) {
    // Array to store remaining burst time for each process
    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = bt[i];

    int current_time = 0;
    int completed_processes = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed_processes < n) {
        int selected_process = -1;
        int highest_priority = 9999; // A large value as initial priority

        // Find the process with the highest priority that has arrived and not completed
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && priority[i] < highest_priority && current_time >= processes[i]) {
                highest_priority = priority[i];
                selected_process = i;
            }
        }

        // If no process is selected, increment time
        if (selected_process == -1) {
            current_time++;
            continue;
        }

        // Execute the selected process for 1 unit of time
        remaining_time[selected_process]--;
        current_time++;

        // If the process is completed, calculate turnaround time and waiting time
        if (remaining_time[selected_process] == 0) {
            completed_processes++;
            int turnaround_time = current_time - processes[selected_process];
            int waiting_time = turnaround_time - bt[selected_process];

            total_waiting_time += waiting_time;
            total_turnaround_time += turnaround_time;

            printf("Process %d:\n", selected_process + 1);
            printf("Turnaround Time: %d\n", turnaround_time);
            printf("Waiting Time: %d\n", waiting_time);
        }
    }

    // Calculate and display average waiting time and average turn-around time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time = %.2f\n", avg_waiting_time);
    printf("Average Turn-Around Time = %.2f\n", avg_turnaround_time);
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

    // Array to store arrival time of processes
    int processes[n];
    for (int i = 0; i < n; i++)
        processes[i] = i;

    // Call function to perform Preemptive Priority scheduling
    preemptivePriorityScheduling(processes, n, bt, priority);

    return 0;
}
