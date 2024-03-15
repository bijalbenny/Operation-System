#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#define SEGSIZE 100
int main(int argc, char *argv[ ])
{
int shmid,cntr; key_t key;
char *segptr;
char buff[]="Hello";
key=ftok(".",'s');
if((shmid=shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666))== -1)
{
if((shmid=shmget(key,SEGSIZE,0))==-1)
{
perror("shmget");
exit(1);
}
}
else
{
printf("Creating a new shared memory seg \n");
printf("SHMID:%d",shmid);
}
system("ipcs –m");
if((segptr=(char*)shmat(shmid,0,0))==(char*)-1)
{
perror("shmat");
exit(1);
}
printf("Writing data to shared memory…\n");
strcpy(segptr,buff);
printf("DONE\n");
printf("Reading data from shared memory…\n");
printf("DATA:-%s\n",segptr);
printf("DONE\n");
printf("Detaching\n");
shmdt(segptr);
printf("DONE\n");
printf("Removing shared memory Segment…\n");
if(shmctl(shmid,IPC_RMID,0)== -1)
printf("Can‟t Remove Shared memory Segment…\n");
else
printf("Removed Successfully");
}












/*#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok(".", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        return 1;
    }
    
    char* str = (char*)shmat(shmid, NULL, 0);
    if (str == (char*)-1) {
        printf("Error attaching shared memory\n");
        return 1;
    }

    printf("Enter a string to store in shared memory: ");
    fgets(str, 1024, stdin);
    printf("String written to shared memory: %s\n", str);
    
    if (shmdt(str) == -1) {
        printf("Error detaching shared memory\n");
        return 1;
    }
    
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory\n");
        return 1;
    }

    return 0;
}
*/
