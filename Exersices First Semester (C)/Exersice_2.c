#include <stdio.h>
int main(void)
{ const float g=9.81;
  float s,u;
  u = g*1;
  s = 0.5*g*1;
  printf("The speed of the object is %.2f m/sec and the distance is %.2f m for 1 second\n",u,s);
  u = g*5;
  s = 0.5*g*25;
  printf("The speed of the object is %.2f m/sec and the distance is %.2f m for 5 seconds",u,s);
  return 0;





}
