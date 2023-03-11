#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{ 
  int hidden,user;
  
  srand(time(NULL));
  hidden =1+rand()%100;
  do
  {
   printf("Guess the hidden number(1 -100)!\n");
   scanf("%d",&user);
   if(user == hidden)
     printf("Congratulations!\nThe hidden number was:%d",hidden);
   else if(user < hidden)
     printf("The hidden number is greater!\n");
   else
     printf("The hidden number is lower!\n");  
  }while(user != hidden);
  
 return 0;
}
