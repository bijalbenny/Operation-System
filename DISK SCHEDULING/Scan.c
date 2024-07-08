#include <stdio.h>
#include <stdlib.h>

void main()
{
   int head,limit,distance,seektime = 0 ,size,direction;

   printf("Enter initial head position\n");
   scanf("%d",&head);

   printf("Enter number of requests\n");
   scanf("%d",&limit);
   int req[limit];

   printf("Enter requests:\n");
   for(int i=0; i< limit ;i++)
    scanf("%d",&req[i]);

    printf("\nEnter total disk size : ");
    scanf("%d",&size);

    printf("\nEnter the head movement direction(1 for high & 0 for low) : ");
    scanf("%d",&direction);

    //Sorting the req in asc
    for(int i=0 ;i < limit ;i++){
        for(int j=i+1; j<limit ;j++){
            if(req[i]>req[j]){
                int temp = req[i];
                req[i]=req[j];
                req[j]=temp;
            }
        }
    }

    if(direction==1){
        seektime += size - 1 - head;
        if (req[0] < head){
            seektime += size - 1 - req[0];
        }
    }
    else{
        seektime += head;
        if (req[limit-1] > head){
            seektime += req[limit-1];
        }
    }
    printf("Total Head Movement is %d\n",seektime);
}
