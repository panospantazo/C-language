#include <stdio.h>

int fibonacci(int);

int main(void)
{
  int n;
  
  printf("Dwse enan arithmo: ");
  scanf("%d",&n);
  printf("O arithmos tha einai: %d",fibonacci(n));

}



int fibonacci(int n)
{
   if(n==1 || n==2)
     return 1;
   else
     return fibonacci(n-1)+fibonacci(n-2);  
 






}
