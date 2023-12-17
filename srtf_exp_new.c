#include <stdio.h>

int main() {
    int a[10], b[10], x[10], i, smallest, count = 0, time = 0, n;
    double avg = 0, tt = 0, end;

    printf("Enter the number of Processes:\n");
    scanf("%d", &n);

    printf("Enter arrival time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter burst time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        x[i] = b[i];
    }

    while (count != n) {
        smallest = -1;

        for (i = 0; i < n; i++) {
            if (a[i] <= time && b[i] > 0 && (smallest == -1 || b[i] < b[smallest])) {
                smallest = i;
            }
        }

        if (smallest == -1) {
            time++;
        } else {
            b[smallest]--;
            time++;

            if (b[smallest] == 0) {
                count++;
                end = time;
                avg = avg + end - a[smallest] - x[smallest];
                tt = tt + end - a[smallest];
            }
        }
    }

    printf("Process \t Arrival Time \t Burst Time \n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\n", i, a[i], x[i]);
    }

    printf("\nAverage waiting time = %lf\n", avg / n);
    printf("Average Turnaround time = %lf", tt / n);

    return 0;
}
