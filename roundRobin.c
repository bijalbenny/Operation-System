#include <stdio.h>

void main() {
        printf("Enter time quantum\n");
        int TIME_QUANTUM;
        scanf("%d",&TIME_QUANTUM);
    printf("Enter number of process\n");
    int limit;
    scanf("%d", &limit);

    int process[limit], bt[limit], rem_bt[limit], wt[limit], tat[limit], i;
    int time = 0;
    int completed = 0;

    printf("Enter processes and burst time\n");
    for (i = 0; i < limit; i++) {
        scanf("%d%d", &process[i], &bt[i]);
        rem_bt[i] = bt[i];
    }

    // Round Robin Scheduling
    while (completed < limit) {
        for (i = 0; i < limit; i++) {
            if (rem_bt[i] > 0) {
                if (rem_bt[i] > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    rem_bt[i] -= TIME_QUANTUM;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i]; 
                    rem_bt[i] = 0;
                    completed++;
                    tat[i] = time;
                }
            }
        }
    }

    float tot_wt = 0, tot_tat = 0;

    printf("Process\tBT\tWT\tTAT\n");
    for (i = 0; i < limit; i++) {
        printf("%d\t%d\t%d\t%d\n", process[i], bt[i], wt[i], tat[i]);
        tot_wt += wt[i];
        tot_tat += tat[i];
    }

    printf("Average WT = %.2f\nAverage TAT = %.2f\n", tot_wt / limit, tot_tat / limit);
}
