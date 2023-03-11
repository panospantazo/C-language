#include <stdio.h>
int main(void)
{
  int x,max;
  printf("Eisagete ton 1o arithmo: ");
  scanf("%d",&x);
  max = x;
  printf("Eisagete ton 1o arithmo: ");
  scanf("%d",&x);
  if(max>x)
    printf("%d",max);
  else
    printf("%d",x);  
  return 0;
}
