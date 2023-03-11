#include <stdio.h>

int isprime(int i); 

main(void)
{
  int arxi,telos,i,x;
  
  printf("Eisagete tin arxi tou diastimatos: ");
  do
   scanf("%d",&arxi);
  while(arxi<=0);
  printf("Eisagete to telos tou diastimatos: ");
  do
   scanf("%d",&telos);
  while(telos<=0 || telos<arxi);
  for(i=arxi;i<=telos;i++)
     if(isprime(i))
       printf("\nTo %d einai prwtos",i);
  
}


int isprime(int i)
{
  int count,a;
  if(i == 1 || i == 0)
    return 0;
  count = 1;		
  for(a=2;a<=i/2;a++)
    if(i % a == 0)
	  count = 0;
	
	
   return count;     
}  
