#include<stdio.h>

void main() {
    int i, n, count = 0, sum = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &n);
    y = n;

    for (i = 0; i < n; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No\t\tBurst Time\t\tTAT\t\tWaiting Time\n");

    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] -= quant;
            sum += quant;
        }

        if (temp[i] == 0 && count == 1) {
            y--;
            printf("Process No[%d]\t\t%d\t\t\t\t%d\t\t\t%d\n", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt += sum - at[i] - bt[i];
            tat += sum - at[i];
            count = 0;
        }

        if (i == n - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }

    avg_wt = (float)wt / n;
    avg_tat = (float)tat / n;

    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
}
