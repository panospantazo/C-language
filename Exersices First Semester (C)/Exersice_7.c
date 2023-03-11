#include <stdio.h>

int add(int);

int main(void)
{ int x,sum;
  printf("Give me a number: ");
  scanf("%d",&x);
  sum = add(x);
  printf("The sum of your digits from your number is: %d",sum);
  return 0;
}


int add(int x)
{
  int i,sum=0;
  while(x>0)
  {
    i=x%10;
    sum += i;
    x=x/10;
  }
  return sum;


}

