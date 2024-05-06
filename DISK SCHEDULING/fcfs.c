#include<stdio.h>

void main() {
    int head, a[20], i, distance, n, seektime = 0;

    printf("\nEnter Head position: ");
    scanf("%d", &head);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    a[n] = head;

    printf("***** FCFS DISK SCHEDULING *****\n");
    for(i = 0; i < n; i++) {
        distance = abs(a[i] - a[i + 1]); //abs is a function used to calculate the absolute value of a number
        printf("Head movement from %d to %d: %d\n", a[i], a[i + 1], distance);
        seektime += distance;
    }

    printf("Total seek time is: %d\n", seektime);

}
