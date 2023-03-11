#include <stdio.h>
int main(void)\
{
  int multi,i,x;
  multi = 1;
  for(i=0;i<3;i++)
  {
    printf("Give me your %d number: ",i+1);
    scanf("%d",&x);
    multi *= x; 
  }
    printf("The multiply of your 3 numbers is %d",multi);
    return 0;
}
