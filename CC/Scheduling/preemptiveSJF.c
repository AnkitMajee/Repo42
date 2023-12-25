//PREEMPTIVE SJF

#include<stdio.h>
#include<math.h>
#include<limits.h>
#include <stdbool.h>
void waiting_time(int *at, int *bt, int *wt, int *rt, int n, float *total_wt)
{
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((at[j] <= t) &&
                (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }

        // Reduce remaining time by one
        rt[shortest]--;

        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        // If a process gets completely
        // executed
        if (rt[shortest] == 0)
        {

            // Increment complete
            complete++;
            check = false;

            // Find finish time of current
            // process
            finish_time = t + 1;

            // Calculate waiting time
            wt[shortest] = finish_time -
                           bt[shortest] -
                           at[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
            *total_wt += wt[shortest];
        }

        t++;
    }
}

void turnaround_time(int *bt, int *wt, int *tat, int n, float *total_tat)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        *total_tat += tat[i];
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], rt[n];
    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time of process P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter burst time of process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    waiting_time(at, bt, wt, rt, n, &total_wt);
    turnaround_time(bt, wt, tat, n, &total_tat);

    printf("Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t %d\t\t %d\t\t  %d\t\t  %d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time: %.2f ms\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f ms", (float)total_tat / n);

    return 0;
}
