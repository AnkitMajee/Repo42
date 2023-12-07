//NONPREMPTIVE SJF

#include <stdio.h>

void waiting_time(int *p, int *bt, int *wt, int n, float *total_wt)
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        *total_wt += wt[i];
    }
}

void turnaround_time(int *p, int *bt, int *wt, int *tat, int n, float *total_tat)
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

    int p[n], bt[n], wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    printf("Enter burst time of the processes: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    // Sorting the processing according to burst time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int tmp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tmp;

                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }

    waiting_time(p, bt, wt, n, &total_wt);
    turnaround_time(p, bt, wt, tat, n, &total_tat);

    printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t %d\t\t  %d\t\t  %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time: %.2f ms\n", total_wt / n);
    printf("Average turnaround time: %.2f ms", total_tat / n);

    return 0;
}