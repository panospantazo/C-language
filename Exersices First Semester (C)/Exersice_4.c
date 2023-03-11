#include <stdio.h>
#include <math.h>
int main(void)
{ float a,b,c,D,r1,r2;
  printf("Give me three numbers:\n");
  scanf("%f%f%f",&a,&b,&c);
  D = pow(b,2)-4*a*c;
  printf("%f",D);
  if(D>=0)
  {
   r1 = (-b+sqrt(D))/(2*a);
   r2 = (-b-sqrt(D))/(2*a);
   if(D>0)
      printf("The roots of the quation are:%.2f,%.2f\n");
   else
      printf("The equation has a double root that is %.2f",r1);
  }
  else
      printf("The equation doesnt have any roots");
   return 0;
}
