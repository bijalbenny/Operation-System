#include<stdio.h>

// Function to calculate absolute value
int absoluteValue(int x) {
    return (x >= 0) ? x : -x;
}

int main() {
    int queue[25], n, headPosition, seek = 0, maxRange, difference;
    float averageSeekTime;

    printf("Enter the maximum range of Disk: ");
    scanf("%d", &maxRange);

    printf("Enter the number of queue requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &headPosition);

    printf("Enter the disk positions to be read (queue): ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    queue[n] = maxRange; // End of the disk

    // Sorting the requests
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    // Calculating seek time
    for(int i = 0; i <= n; i++) {
        difference = absoluteValue(queue[i + 1] - queue[i]);
        seek += difference;
        printf("Disk head moves from position %d to %d with Seek %d\n", queue[i], queue[i + 1], difference);
    }

    // Calculating average seek time
    averageSeekTime = (float)seek / n;

    // Displaying seek times
    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %f\n", averageSeekTime);

    return 0;
}
