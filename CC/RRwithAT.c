#include<stdio.h>

// Function to find waiting time for all processes
void waiting_time(int n, int bt[], int rt[], int wt[], int tq, int *total_wt, int at[]) {
    int t = 0;

    // Continue until all processes are done
    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= t) {
                done = 0;

                if (rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i] - at[i];
                    rt[i] = 0;
                    *total_wt += wt[i];
                }
            }
        }

        if (done == 1)
            break;
    }
}

// Function to find turnaround time for all processes
void turnaround_time(int n, int bt[], int wt[], int tat[], int *total_tat) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        *total_tat += tat[i];
    }
}

// Driver code
int main() {
    int n;

    printf("Enter Total number of Processes: ");
    scanf("%d", &n);

    int total_wt = 0, total_tat = 0, bt[n], rt[n], wt[n], tat[n], at[n];

    // Input burst times and arrival times, initialize remaining times
    for (int i = 0; i < n; i++) {
        printf("Enter burst time of process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter arrival time of process P%d: ", i + 1);
        scanf("%d", &at[i]);
        rt[i] = bt[i];
    }

    int tq;
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Calculate waiting time and turnaround time
    waiting_time(n, bt, rt, wt, tq, &total_wt, at);
    turnaround_time(n, bt, wt, tat, &total_tat);

    // Print the result table
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    // Print average waiting time and average turnaround time
    printf("\nAverage Waiting Time = %.2f ms\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f ms\n", (float)total_tat / n);

    return 0;
}
