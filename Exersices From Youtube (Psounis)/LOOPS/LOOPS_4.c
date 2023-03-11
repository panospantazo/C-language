#include <stdio.h>
#define SIZE 5
int main(void)
{
  int a[SIZE],prod=1,i;
  for(i=0;i<SIZE;i++)
  {
    printf("Give me your %dst number between 1-8\n",i+1);
    do
      scanf("%d",&a[i]);
    while(a[i]<1 || a[i]>8);
  }
  for(i=0;i<SIZE;i++)
  {
     prod *= a[i];
  }
  printf("The product of the numbers is: %d",prod);
  return 0;
}
