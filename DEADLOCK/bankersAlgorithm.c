#include<stdio.h>
#include <stdlib.h>

void main() {
 int num,res,i,j,count=0,flag=0,exec=0,k=0;
 printf("Enter the number of processes :  ");
 scanf("%d",&num);
 int visited[num];
 int safeSeq[num];
  printf("Enter the number of resources :  ");
 scanf("%d",&res);
 int alloc[num][res],max[num][res],need[num][res],avail[res];
 printf("Enter available resources :  ");
 for(i=0;i<res;i++)
		scanf("%d",&avail[i]);
 for(i=0;i<num;i++)	{
    visited[i]=0;
    printf("Enter the maximum of P%d : ",i);
    for(j=0;j<res;j++)
        scanf("%d",&max[i][j]);
    printf("Enter the allocation of P%d : ",i);
    for(j=0;j<res;j++)
        scanf("%d",&alloc[i][j]);
    //need = max-alloc
    for(j=0;j<res;j++)
        need[i][j]=max[i][j]-alloc[i][j];

 }
 //To print
 printf("\nAllocation	Max 	Need\n");
 for(i=0;i<num;i++){
    for(j=0;j<res;j++)
        printf("%d ",alloc[i][j]);

		for(j=0;j<res;j++)
			printf("%d ",max[i][j]);
		printf("\t");
		for(j=0;j<res;j++)
			printf("%d ",need[i][j]);
        printf("\n");
 }
 while(count<num){
    flag=0;
    for(i=0;i<num;i++){
        exec=0;
        for(j=0;j<res;j++){
            if(need[i][j]<=avail[j])
                exec++;
        }
        if(exec==res&&visited[i]==0){
            for(j=0;j<res;j++)
                avail[j]+=alloc[i][j];
                //available = available + current Allocation
            flag=1;
            visited[i]=1;
            count++;
            safeSeq[k++]=i;//to store the safe sequence
        }
    }
    if (flag==0){
        printf("no safe sequence\n");
        exit(0);
    }

 }

 printf("\nSafe Sequence : \n");
	printf("<");
	for(i=0;i<num;i++)
		printf("P%d ",safeSeq[i]);
	printf(">\n");

}
