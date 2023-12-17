#include<stdio.h>
#include<stdlib.h>

struct Order{
    int id;
    int deadline;
    int time;
};

void schedule_orders(struct Order orders[],int num_orders){
    //sorting
    for(int i=0;i<num_orders-1;i++){
        for(int j=i+1;j<num_orders-i-1;j++){
            if(orders[j].deadline>orders[j+1].deadline){
                //swapping
                struct Order temp=orders[j];
                orders[j]=orders[j+1];
                orders[j+1]=temp;
            }
        }
    }

    int current_time=0;
    printf("\nScheduled Orders:\n");
    for(int i=0;i<num_orders;i++){
        if(current_time+orders[i].time<=orders[i].deadline){
            printf("Order: %d(Deadline: %d,Processing Time:%d)\n",orders[i].id,orders[i].deadline,orders[i].time);
            current_time+=orders[i].time;
        }
    }
}

int main(){
    int num_orders;
    printf("\nEnter the number of orders:");
    scanf("%d",&num_orders);

    struct Order *orders=(struct Order *)malloc(num_orders * sizeof(struct Order));

    if(orders==NULL){
        printf("\nMEMORY ALLOCATION FAILED");
        return EXIT_FAILURE;
    }

    printf("Enter the order details: ");
    for(int i=0;i<num_orders;i++){
        printf("Order %d - Deadline: ", i + 1);
        scanf("%d", &orders[i].deadline);
        printf("Order %d - Processing Time: ", i + 1);
        scanf("%d", &orders[i].time);
        orders[i].id = i + 1;
    }

    schedule_orders(orders,num_orders);

    free(orders);
}