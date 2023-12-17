#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid; //process id
    int arrival_time;
    int burst_time;
    int remaining_time;
};

int main(){
    int n,quantum;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the time Quantum: ");
    scanf("%d",&quantum);
    struct process p[n];
    int waiting_time[n],turnaround_time[n],completion_time[n];
    int total_waiting_time=0,total_turnaround_time=0;
    printf("\nEnter the arrival and Burst time for each process:\n");
    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        p[i].pid=i+1;
        printf("arrival time: ");
        scanf("%d",&p[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d",&p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }

    int time=0,flag=0;
    while(1){
        flag=0;
        for(int i=0;i<n;i++){
            if(p[i].remaining_time>0){
                flag=1;
                if(p[i].remaining_time<=quantum){
                    time+=p[i].remaining_time;
                    completion_time[i]=time;
                    p[i].remaining_time=0;
                }else{
                    time+=quantum;
                    p[i].remaining_time-=quantum;
                }
            }
        }
        if(flag==0)
        break;
    }
    for(int i=0;i<n;i++){
        turnaround_time[i]=completion_time[i]-p[i].arrival_time;
        waiting_time[i]=turnaround_time[i]-p[i].burst_time;
        total_waiting_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }
    printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n");
for(int i=0; i<n; i++) {
    printf("%d\t %d\t\t %d\t\t %d\t\t\t %d\t\t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time,
    completion_time[i], waiting_time[i], turnaround_time[i]);
}
printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time/n);
printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround_time/n);
return 0;

}