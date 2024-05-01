#include<stdio.h>
void main()
   {
    int Processes[5];
    
    struct memory{    //Memory available
       int size;
       int flag;
     }m[5];
     
    printf("Enter the memory used by the processes\n");
    for (int i=0;i<5;i++)
        scanf("%d",&Processes[i]);
        
    printf("Enter the size of memory slots available :\n");
    for (int i=0;i<5;i++)
       {
        scanf("%d",&m[i].size);
        m[i].flag=0;
       }
       
    //Allocation
    for (int i=0;i<5;i++)
       {
        int j;
        for (j=0;j<5;j++)
           {
            if(Processes[i]<=m[j].size)
               {
                //----------------------------
                if (m[j].flag==1)
                   continue;
                else
                   {
                    printf("Processes %d is allocated to %d Memory\n",i+1,m[j].size);
                    m[j].flag=1;
                    break;
                   }
               }
           }
           if (j==5)
               printf("Processes %d cannot be allocated\n",i+1);
       }   
   }
 
/*#include<stdio.h>

int main() {
    int process[4], i, j;
    struct Memory {
        int size, flag;
    } m[4];

    printf("Enter the memory used by the processes:\n");
    for (i = 0; i < 4; i++)
        scanf("%d", &process[i]);

    printf("Enter the size of available memory slots:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &m[i].size);
        m[i].flag = 0;
    }

    // Allocation
    for (i = 0; i < 4; i++) {
        int allocated = 0;
        for (j = 0; j < 4; j++) {
            if (process[i] <= m[j].size&&m[j].flag==0) {

                    printf("Process %d is allocated in memory block %d\n", i + 1, m[j].size);
                    m[j].flag = 1;
                    allocated = 1;
                    break;

            }
        }
        if (allocated == 0)
            printf("Process %d is not allocated\n", i + 1);
    }

    return 0;
}
*/ 
 
 
 
 
 
 
