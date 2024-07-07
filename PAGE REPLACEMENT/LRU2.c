#include <stdio.h>
#include <limits.h>  //to use INT_MAX
void main()
{
    int fNo, rNo, i, pgf = 0;
    printf("Enter no of frames:\n");
    scanf("%d", &fNo);
    printf("Enter no of requests:\n");
    scanf("%d", &rNo);
    int frame[fNo], req[rNo], used[fNo];
    for(i = 0; i < fNo; i++){
        frame[i] = -1;  // Initialize frames to -1 indicating they are empty
        used[i] = 0;    // Initialize used array for LRU tracking
    }
    printf("Enter reference string:\n");
    for(i = 0; i < rNo; i++)
        scanf("%d", &req[i]);
    printf("Page replacement using LRU:\n");
    for(i = 0; i < rNo; i++){
        int avail = 0;
        printf("%d : ", req[i]);
        // Check if page already exists in frame
        for(int a = 0; a < fNo; a++){
            if(frame[a] == req[i]){
                avail = 1;
                used[a] = i + 1;  // Update the time of last use (using i + 1 because i starts from 0)
                break;
            }
        }
        // If page fault occurs, replace the least recently used page
        if(avail == 0){
            int leastUsed = INT_MAX;
            int replaceIndex = -1;
            // Find the least recently used page
            for(int a = 0; a < fNo; a++){
                if(used[a] < leastUsed){
                    leastUsed = used[a];
                    replaceIndex = a;
                }
            }
            // Replace the least recently used page with the current page
            frame[replaceIndex] = req[i];
            used[replaceIndex] = i + 1;  // Update the time of last use
            pgf++;
        }
        // Print current state of frames after each request
        for(int a = 0; a < fNo; a++){
            printf("%d\t", frame[a]);
        }
        printf("\n");
    }
    printf("Number of page faults = %d\n", pgf);
}
 /*
                   OUTPUT
      Enter no of frames:
4
Enter no of requests:
13
Enter reference string:
7 0 1 2 0 3 0 4 2 3 0 3 2
Page replacement using LRU:
7 : 7   -1      -1      -1
0 : 7   0       -1      -1
1 : 7   0       1       -1
2 : 7   0       1       2
0 : 7   0       1       2
3 : 3   0       1       2
0 : 3   0       1       2
4 : 3   0       4       2
2 : 3   0       4       2
3 : 3   0       4       2
0 : 3   0       4       2
3 : 3   0       4       2
2 : 3   0       4       2
Number of page faults = 6
*/
