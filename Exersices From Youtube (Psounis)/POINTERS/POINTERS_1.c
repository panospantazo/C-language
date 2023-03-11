#include <stdio.h>
#include <math.h>


int rizes(float a,float b,float c,float *x1,float *x2);


int main(void)
{
   float a,b,c,x1,x2;
   int pl;
   printf("Dwse to a: ");
   do
     scanf("%f",&a);
   while(a == 0);  
   printf("Dwse to b: ");
   scanf("%f",&b);
   printf("Dwse to c: ");
   scanf("%f",&c);
   pl = rizes(a,b,c,&x1,&x2);
   if(pl == 2)
     printf("Oi rizes tis exiswseis einai %.1f kai %.1f",x1,x2);
   else if(pl == 1)
     printf("H exuswsei exei mia dipli riza %.1f",x1);
   else
     printf("H exiswsei den exei rizes!") ;  
 
  return 0;
}




int rizes(float a,float b,float c,float *x1,float *x2)
{
   float dia;
   dia = pow(b,2)-4*a*c;
   if(dia>0)
   {
     *x1 = (-b+sqrt(dia))/(2*a);
     *x2 = (-b-sqrt(dia))/(2*a);   
      return 2;
   }
   else if(dia == 0)
   {
     *x1 = -b/(2*a);
      return 1;   
   }
   else
   {
     return 0;
   }
}
