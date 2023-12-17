#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTime(struct Process processes[], int n) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        processes[i].waiting_time = 0;
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortest = -1;
        int minRemainingTime = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= currentTime && remaining_time[i] < minRemainingTime && remaining_time[i] > 0) {
                minRemainingTime = remaining_time[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            remaining_time[shortest]--;
            currentTime++;

            if (remaining_time[shortest] == 0) {
                completed++;
                processes[shortest].turnaround_time = currentTime - processes[shortest].arrival_time;
                processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
            }
        }
    }
}

int main() {
    int n = 6; // Number of processes
    struct Process processes[] = {
        {1, 0, 7, 0, 0},
        {2, 0, 5, 0, 0},
        {3, 0, 3, 0, 0},
        {4, 0, 1, 0, 0},
        {5, 0, 2, 0, 0},
        {6, 0, 1, 0, 0},
    };

    calculateWaitingTime(processes, n);

    float avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waiting_time;
    }

    avgWaitingTime /= n;

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
