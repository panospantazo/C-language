#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(void)
{
  int a[SIZE],x,k;
  srand(time(NULL));
  printf("Give me a number between 20-100: ");
  do
    scanf("%d",&x);
  while(x<20 || x>100);
  k=0;
  for(int i=0;i<x;i++)
  {
    a[i]=rand();
    printf("%d)%d\n",k,a[i]);
    k += 1;
  }
  return 0;
}
