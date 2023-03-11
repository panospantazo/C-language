#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 100
#define N 200
int main(void)
{
  int lines,collums,a[M][N],i,j;
  
  srand(time(NULL));
  	
  printf("Give me the amount of lines that you want to process(1-10):");
  do
    scanf("%d",&lines);
  while(lines<1 || lines>10);
  printf("Give me the amount of collums that you want to process(2-10):");
  do
    scanf("%d",&collums);
  while(collums<2 || collums>10);
  for(i = 0;i<lines;i++)
    for(j=0;j<collums;j++)
    {
      a[i][j] = 1+rand()%10;
    }
  for(i = 0;i<lines;i++)
  {
    for(j=0;j<collums;j++)
	  printf(" %d\t",a[i][j]);
    printf("\n");
  }
  return 0; 
}
