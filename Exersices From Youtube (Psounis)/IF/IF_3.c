#include <stdio.h>
int main()
{
   int x,max,max2;
   printf("Eisagete ton 1o arithmo: ");
   scanf("%d",&x);
   max = x;
   printf("Eisagete ton 2o arithmo: ");
   scanf("%d",&x);
   if(max<x)
   {
    max2 = max;
    max = x;
   }
   else
    max2 = x;
   printf("Eisagete ton 3o arithmo: ");
   scanf("%d",&x);
   if(x>=max)
     printf("%d,%d,%d",x,max,max2);
   else if(x<max && x>=max2)
     printf("%d,%d,%d",max,x,max2);
   else if(x<max2)
     printf("%d,%d,%d",max,max2,x); 	  	   

   return 0;







}
