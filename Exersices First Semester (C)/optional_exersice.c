#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 6
int main(void)
{
  int f,i,j,cnt,a[SIZE],num,min;
  srand(time(NULL));
  for(i=0;i<SIZE;i++)
  {
    f=0; 
	if(i==0)
     a[i] = 1+rand()%49;
    else
	{
	  num = 1+rand()%49;  
	  while(f==0)
	  {
	  	cnt = 0; 
	    for(j=0;j<i;j++)
		{
		  if(a[j]==num)
		  {
		    num = 1+rand()%49;		    
			break;
	      }
		  else
		    cnt +=1;
		}
		if(cnt == i)
		  f = 1;
	  }   
	  a[i] = num;
	}
  }
  printf("NOT SORTED ARRAY!\n");
  printf("[");
  for(i=0;i<SIZE;i++)
    printf("%d ",a[i]);
  printf("]");
  
  
   for(int i = 0; i < SIZE - 1; i++) 
   {
        min = i;
        for(int j = i + 1; j < SIZE; j++) {
            if(a[min] > a[j]) {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    
    printf("\nSORTED ARRAY!\n");
  printf("[");
  for(i=0;i<SIZE;i++)
    printf("%d ",a[i]);
  printf("]");
  
  return 0;
}
