#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5
#define N 8
int main(void)
{
  int a[M][N],i,j;
  
  srand(time(NULL));
  for(i = 0;i<M;i++)
    for(j = 0;j<N;j++)
      a[i][j] = rand()%200;
     
   for(i = 0;i<M;i++)
   {
    printf("\n");
    for(j = 0;j<N;j++)
       printf("%3d\t",a[i][j]);
   }
   return 0;    
}
