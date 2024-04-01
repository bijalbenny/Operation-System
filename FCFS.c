#include <stdio.h>

void main() {
    printf("Enter number of process\n");
    int limit;
    scanf("%d", &limit);
    
    int process[limit], bt[limit], wt[limit], tat[limit], i;
    
    printf("Enter processes and corresponding burst time\n");
    for (i = 0; i < limit; i++) {
        scanf("%d%d", &process[i], &bt[i]);
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

    printf("Process\tBT\tWT\tTAT\n");
    for (i = 0; i < limit; i++) {
        printf("%d\t%d\t%d\t%d\n", process[i], bt[i], wt[i], tat[i]);
    }

    printf("Average WT = %.2f\nAverage TAT = %.2f", tot_wt / limit, tot_tat / limit);
}
