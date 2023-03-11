#include <stdio.h>
int main(void)
{
  int age;	
  printf("Give me your age: ");
  scanf("%d",&age);
  if(age<18)
    printf("You are still a child!");
  else if(age<=65)
    printf("You are an adult!");
  else
    printf("You are retired");	  
  return 0;		  
}
