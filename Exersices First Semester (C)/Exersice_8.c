#include <stdio.h>


int factorial(int numb);


int main(void)
{ int i=0,numb;
  printf("Give me a positive number: ");
  do{
	scanf("%d",&numb);
	i += 1;
	if(i>=1)
	  printf("I require a positive number!\n");
  }while(numb<0);
  printf("The factorial of number %d is %d",numb,factorial(numb));
  return 0; 
}




int factorial(int numb)
{
int i=1,result = 1;
  if(numb!=0)
  {
  while(i<=numb)
  {
    result *= i ;
    i += 1;
  } 
  return result;
  } 
  else
    return 1;
}
