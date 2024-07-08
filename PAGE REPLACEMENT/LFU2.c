#include <stdio.h>
void main()
{
    int fNo,rNo,i;
    printf("Enter no of frames\n");
    scanf("%d",&fNo);
    printf("Enter no of requests\n");
    scanf("%d",&rNo);
    int frame[fNo],req[rNo],freq[fNo],time[fNo];
    for(i=0;i<fNo;i++){
        frame[i]=-1;
        freq[i]=0;
        time[i]=0;
    }
    printf("Enter requests\n");
    for(i=0;i<rNo;i++)
        scanf("%d",&req[i]);
    printf("Page replacement using LFU:\n");
    int j,pgf=0;
    for(i=0;i<rNo;i++){
        int hit=0;
        printf("%d\t",req[i]);
        for(j=0;j<fNo;j++){
            if(frame[j]==req[i]){
                hit=1;
                freq[j]++;
                time[j]=i;
                break;
            }
        }
        if(hit==0){
            int minFreq=freq[0],minIndex=0,oldest=time[0];
            for(j=1;j<fNo;j++){
                if(frame[j]==-1){
                    minIndex=j;
                    break;
                  }
                 else if(freq[j]<minFreq||(freq[j]==minFreq&&time[j]<oldest){
                    minFreq=freq[j];
                    minIndex=j;
                    oldest=time[j];
                }
            }
            frame[minIndex]=req[i];
            freq[minIndex]=1;
            time[minIndex]=i;
            pgf++;
        }
        for(j=0;j<fNo;j++)
            printf("%d\t",frame[j]);
        printf("\n");
    }
      printf("Page Fault = %d",pgf);
}


 /**************************************
                         OUTPUT
Enter no of frames
3
Enter no of requests
7
Enter requests
1 2 3 4 2 1 5
Page replacement using LFU:
1       1       -1      -1
2       1       2       -1
3       1       2       3
4       4       2       3
2       4       2       3
1       1       2       3
5       5       2       3
Page Fault = 6
  */
