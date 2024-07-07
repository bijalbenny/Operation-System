#include <stdio.h>
#include <stdlib.h>

void main()
{
    int head,n,size,totalHeadMovement=0,direction,i;
    printf("\nEnter the number of requests : ");
    scanf("%d",&n);
    printf("Enter the request sequence\n");
    int req[n];
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);
    printf("\nEnter initial head position : ");
    scanf("%d",&head);
    printf("\nEnter total disk size : ");
    scanf("%d",&size);
    printf("\nEnter the head movement direction(1 for high & 0 for low) : ");
    scanf("%d",&direction)
    for(i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(req[i]>req[j]){
                int temp = req[i];
                req[i]=req[j];
                req[j]=temp;
            }
        }
    }
    int index=0;
    while(index<n&&head>=req[index])
        index++;
    if(direction==1){
        for(i=index;i<n;i++){
            totalHeadMovement+=abs(req[i]-head);
            head=req[i];
        }
        totalHeadMovement+=abs(size-req[n-1]-1);
        totalHeadMovement+=size-1;
        head=0;
        for(i=0;i<index;i++){
            totalHeadMovement+=abs(req[i]-head);
            head=req[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            totalHeadMovement+=abs(req[i]-head);
            head=req[i];
        }
        totalHeadMovement+=abs(req[0]-0);
        totalHeadMovement+=size-1;
        head=size-1;
        for(i=n-1;i>=index;i--){
            totalHeadMovement+=abs(req[i]-head);
            head=req[i];
        }
    }
    printf("Total Head Movement is %d\n",totalHeadMovement);
}
