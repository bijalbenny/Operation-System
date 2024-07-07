#include <stdio.h>
#include <stdlib.h>
void main()
{
   int maxRange,queue[25],n,head,seektime=0,distance;
   printf("\nEnter maximum range of disk :  ");
   scanf("%d",&maxRange);
   printf("\nEnter initial head position : ");
   scanf("%d",&head);
   printf("\nEnter number of requests : ");
   scanf("%d",&n);
   printf("Enter the requests\n");
   for(int i=0;i<n;i++)
    scanf("%d",&queue[i]);
   queue[n]=maxRange;
   for(int i=0;i<=n;i++){
    for(int j=i+1;j<=n;j++){
        if(queue[i]>queue[j]){
            int temp = queue[i];
            queue[i]=queue[j];
            queue[j]=temp;
        }
    }
   }
   for(int i=0;i<n;i++){
    distance=abs(queue[i+1]-queue[i]);
    seektime+=distance;
    printf("Head movement from %d to %d is %d\n",queue[i],queue[i+1],distance);
   }
   printf("Seektime is %d\n",seektime);
   printf("Avg seektime is %d\n",seektime/n);
}


/* #include<stdio.h>

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
    for(int i = 0; i < n; i++) {  // Change the loop condition to iterate up to n - 1
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
*/
