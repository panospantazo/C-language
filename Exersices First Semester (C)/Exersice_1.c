#include <stdio.h>
#include <math.h>
int main(void)
{ const float PE=3.14;
  int h,r;
  float E;
  printf("Give me the height and the ray\n");
  scanf("%d%d",&h,&r);
  E = PE*r*(sqrt(pow(r,2)+pow(h,2))+r);
  printf("%f",E);
  return 0;  
}

