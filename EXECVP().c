//one.c
#include<stdio.h>
#include<unistd.h>
int main()
{
int i;
printf("I am the program called by the first process");
for(i=1;i<10;i++)
{
printf("%d*%d\n",i,i);
}
return 0;}

//first.c

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
char *args[]={"./ex",NULL};
execvp(args[0],args);
printf("End");
}
