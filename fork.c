#include<stdio.h>
#include<unistd.h>

void main() {
 pid_t id;
 id = fork();
 if(id==0)
 {
 printf("Child Process\n");
 printf("process id is %d\n",getpid());
 printf("parent id is %d\n",getppid());
 int num;
 printf("Enter a number\n");
 scanf("%d",&num);
 if(num%2==0)
 printf("%d is even\n",num);
 else
 printf("%d is odd\n",num);
 }
 else if(id>0){
  wait(NULL);
 printf("Parent Process\n");
 printf("process id is %d\n",getpid());
 int num,i;

 printf("Enter limit\n");
 scanf("%d",&num);
 for(i=1;i<=num;i++){
  printf("%d\t",i);
 }
 
}
else
printf("Fork failed\n");
 }

