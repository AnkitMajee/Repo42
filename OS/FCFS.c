//FCFS

#include<stdio.h>

void waiting_time(int n,int bt[],int wt[],float *total_wt){
    wt[0] = 0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
        *total_wt = *total_wt+wt[i];    
    }
}

void turnaround_time(int n,int bt[],int wt[],int tat[],float *total_tat){
    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
        *total_tat = *total_tat + tat[i];
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n],wt[n],tat[n];
    float total_wt = 0,total_tat = 0;

    printf("Enter the burst time of the processes: ");
    for(int i=0;i<n;i++){
        scanf("%d", &bt[i]);
    }

    waiting_time(n,bt,wt,&total_wt);
    turnaround_time(n,wt,bt,tat,&total_tat);

    printf("Process\t Burst Time\t Waiting Time\t Turnaround Time");
    printf("\n");

    for(int i=0;i<n;i++){
        printf("%d\t  %d\t\t  %d\t\t  %d", i+1,bt[i],wt[i],tat[i]);
        printf("\n");
    }

    printf("Average waiting time: %.2f", total_wt/n);
    printf("\n");
    printf("Average turnaround time: %.2f", total_tat/n);

    return 0;
}
