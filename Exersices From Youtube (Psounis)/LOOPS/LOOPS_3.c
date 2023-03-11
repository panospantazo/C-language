#include <stdio.h>
#define SIZE 10
int main(void)
{
  int a[SIZE],i,sum=0;
  for(i=0;i<SIZE;i++)
  {
    printf("Give me your %dst number: ",i+1);
    scanf("%d",&a[i]);
  }
  for(i = 0;i<SIZE;i++)
    sum += a[i];
  printf("%2d",sum);
  return 0;
}
