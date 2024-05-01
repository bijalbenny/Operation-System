
#include<stdio.h>
void main()
   {
    int Processes[5];

    struct memory{    //Memory available
       int size;
       int flag;
     }m[5],temp;

    printf("Enter the memory used by the processes\n");
    for (int i=0;i<5;i++)
        scanf("%d",&Processes[i]);

    printf("Enter the size of memory slots available :\n");
    for (int i=0;i<5;i++)
       {
        scanf("%d",&m[i].size);
        m[i].flag=0;
       }
    //swapping in asc order
    for (int i=0;i<4;i++)
       {
        for (int j=i+1;j<5;j++)
          {
             if (m[i].size>m[j].size)
                {
                 temp=m[i];
                 m[i]=m[j];
                 m[j]=temp;
                }
          }
       }

    //Allocation
    for (int i=0;i<5;i++)
       {
        int j;
        int allocated=0;
        for (j=0;j<5;j++)
           {
            if(Processes[i]<=m[j].size&&m[j].flag==0)
               {

                    printf("Processes %d is allocated to %d Memory\n",i+1,m[j].size);
                    m[j].flag=1;
                    allocated =1;
                    break;

               }
           }
           if (allocated==0)
               printf("Processes %d cannot be allocated\n",i+1);
       }
   }















/*


#include<stdio.h>
void main(){
int memblok,limit,i,j;
printf("Enter the number of memory blocks and no of process\n");
scanf("%d%d",&memblok,&limit);
struct memory{
int size,alloc;
}m[memblok];
struct process{
int psize,flag;
}p[limit];
printf("Enter the size of memory block\n");
for(i=0;i<memblok;i++){
scanf("%d",&m[i].size);
m[i].alloc=0;
}
for(i=0;i<memblok;i++){
 for(j=i+1;j<memblok;j++){
   if(m[i].size>=m[j].size){
   int temp=m[i].size;
       m[i].size=m[j].size;
       m[j].size=temp;
    }
  }
}
printf("Enter the size of  processes\n");
for(i=0;i<limit;i++){
scanf("%d",&p[i].psize);
p[i].flag=0;
}
for(i=0;i<limit;i++){
 for(j=0;j<memblok;j++){
  if(p[i].flag==0){
   if(p[i].psize<=m[j].size){
      if(m[j].alloc==1)
        continue;
      else{
        m[j].alloc=1;
        p[i].flag=1;
        printf("process %d is allocated in %d block\n",p[i].psize,m[j].size);
        }
       }
     }
   }
  }
for(i=0;i<limit;i++){
  if(p[i].flag==0)
   printf("There is no space for %d process\n",p[i].psize);
}
}*/
