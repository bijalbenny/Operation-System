#include <stdio.h>

void main() {
    printf("Enter number of process\n");
    int limit;
    scanf("%d", &limit);
    
    int process[limit], bt[limit], wt[limit], tat[limit], priority[limit], i, j, temp;
    
    printf("Enter processes, burst time, and priority\n");
    for (i = 0; i < limit; i++) {
        scanf("%d%d%d", &process[i], &bt[i], &priority[i]);
    }
    
    for (i = 0; i < limit - 1; i++) {
        for (j = 0; j < limit - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
                
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
    
    wt[0] = 0; 
    tat[0] = bt[0]; 

    float tot_wt = wt[0], tot_tat = tat[0]; 

    for (i = 1; i < limit; i++) { 
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
    }

    printf("Process\tBT\tPriority\tWT\tTAT\n");
    for (i = 0; i < limit; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", process[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("Average WT = %.2f\nAverage TAT = %.2f\n", tot_wt / limit, tot_tat / limit);
}
