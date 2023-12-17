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

void calculate_waiting_time(struct Process processes[], int n) {
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time > currentTime) {
            currentTime = processes[i].arrival_time;
        }

        processes[i].waiting_time = currentTime - processes[i].arrival_time;
        totalWaitingTime += processes[i].waiting_time;

        currentTime += processes[i].burst_time;
        processes[i].completion_time = currentTime;

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        totalTurnaroundTime += processes[i].turnaround_time;
    }

    double avgWaitingTime = (double)totalWaitingTime / n;
    double avgTurnaroundTime = (double)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2lf", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2lf", avgTurnaroundTime);
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
    }

    calculate_waiting_time(processes, n);
    print_table(processes, n);

    return 0;
}
