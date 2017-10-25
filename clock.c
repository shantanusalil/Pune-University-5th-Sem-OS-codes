#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
int hh=3,mm=50,ss=58;
void *hours(void *arg)
{
 printf("hourshand thread is created\n");
 sleep(1);
 while(1)
 {
   if(mm==59)
   {
       hh+=1;
       mm=0;
   }
 }
}
void *minu(void *arg)
{
  printf("minutehand thread is created\n");
  sleep(1);
  while(1)
  {    
    if(ss==59)
       {
         mm+=1;
         ss=0;
       }
  }
}
void *secu(void *arg)
{
  printf("secondhand thread is created\n");
  sleep(1);
  while(1)
{
ss++;
   printf("%d: %d: %d\n",hh,mm,ss);
   sleep(1);
   system("clear");
}
}
int main()
{
 pthread_t hrs,min,sec;
 pthread_create(&sec,NULL,secu,NULL);
 pthread_create(&min,NULL,minu,NULL);
 pthread_create(&hrs,NULL,hours,NULL);
 pthread_join(sec,NULL);
 pthread_join(min,NULL);
 pthread_join(hrs,NULL);
return 0;
}
