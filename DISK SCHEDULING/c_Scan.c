#include<stdio.h>
#include<stdlib.h>

int main() {
    int RQ[100], n, TotalHeadMoment = 0, initial, size, move;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Requests sequence: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Enter the head movement direction (1 for high, 0 for low): ");
    scanf("%d", &move);

    // Sort the request array
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index = 0;
    // Find the index where initial head position lies
    while(index < n && initial >= RQ[index]) {
        index++;
    }

    // Movement towards high value
    if(move == 1) {
    


    for(int i = index; i < n; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // Last movement for max size
        TotalHeadMoment += abs(size - RQ[n - 1] - 1);
        // Movement from max to min disk
        TotalHeadMoment += size - 1;
        initial = 0;
        for(int i = 0; i < index; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    // Movement towards low value
    else {
        for(int i = index - 1; i >= 0; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // Last movement for min size
        TotalHeadMoment += abs(RQ[0] - 0);
        // Movement from min to max disk
        TotalHeadMoment += size - 1;
        initial = size - 1;
        for(int i = n - 1; i >= index; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total head movement is %d\n", TotalHeadMoment);

    return 0;
}

