#include <stdio.h>
int main(void)
{
   int M,N,i,j;
   M = 10;
   N = 20;
   i = 0;
   while(i<=M)
    {
     j = 0;	
     while(j<=N)
	 {
        printf("X");
        j++;
     }
     printf("\n");
     i++;
    }
 return 0;
}
