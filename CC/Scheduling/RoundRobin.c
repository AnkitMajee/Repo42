// ROUND ROBIN

#include<stdio.h>

void waiting_time(int n,int *bt,int *rt,int *wt,int tq,int *total_wt){
   int remain = n;
   int flag = 0;
   for(int time=0,count=0;remain!=0;)
   {
        if(rt[count]<=tq && rt[count]>0)
        {
        time+=rt[count];
        rt[count]=0;
        flag=1;
        }
        else if(rt[count]>0)
        {
        rt[count]-=tq;
        time+=tq;
        }
        if(rt[count]==0 && flag==1)
        {
        remain--;
        
        wt[count] = time - bt[count];
        *total_wt += wt[count];
        
        flag=0;
        }
        if(count==n-1)
        count=0;
        else if(0<=time)
        count++;
        else
        count=0;
   }
}

void turnaround_time(int n,int *bt,int *wt,int *tat,int *total_tat){
    for(int i=0;i<n;i++){
        tat[i] = bt[i]+wt[i];
        *total_tat += tat[i];
    }
}
 
int main()
{
 
  int n;
 
  printf("Enter Total number of Process: ");
  scanf("%d",&n);
  
   int total_wt=0,total_tat=0,bt[n],rt[n];
  
  for (int i = 0; i < n; i++)
   {
       printf("Enter burst time of process P%d: ", i + 1);
       scanf("%d", &bt[i]);
       rt[i] = bt[i];
   }

  int tq,wt[n],tat[n];
  printf("Enter Time Quantum: ");
  scanf("%d",&tq);
  
  waiting_time(n,bt,rt,wt,tq,&total_wt);
  turnaround_time(n,bt,wt,tat,&total_tat);
  
  printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");
  for (int i = 0; i < n; i++)
  {
      printf("%d\t\t %d\t\t\t  %d\t\t\t\t  %d\n", i + 1, bt[i], wt[i], tat[i]);
  } 
  
  printf("Average Waiting Time = %.2f ms\n",(float)total_wt/n);
  printf("Avg Turnaround Time = %.2f ms", (float)total_tat/n);
  
  return 0;
 }