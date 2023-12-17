#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void calculate_srtf(struct Process processes[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int shortestIndex = -1;
        int shortestRemainingTime = 9999; // A large value as initial remaining time

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= currentTime && processes[i].remaining_time > 0 &&
                processes[i].remaining_time < shortestRemainingTime) {
                shortestRemainingTime = processes[i].remaining_time;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
        } else {
            processes[shortestIndex].remaining_time--;
            currentTime++;

            if (processes[shortestIndex].remaining_time == 0) {
                completedProcesses++;
                processes[shortestIndex].completion_time = currentTime;
                processes[shortestIndex].waiting_time = currentTime - processes[shortestIndex].arrival_time -
                                                           processes[shortestIndex].burst_time;
                processes[shortestIndex].turnaround_time =
                    processes[shortestIndex].completion_time - processes[shortestIndex].arrival_time;

            }
        }
    }
}

void print_table(struct Process processes[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    struct Process processes[100];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculate_srtf(processes, n);
    print_table(processes, n);

    return 0;
}
