#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct kati{
   char a[100];
   int x;
};


int calc(int *,int );

int main(void)
{
  srand(time(NULL));
  int *ptr1,*ptr,i,*num,k,x;
  struct kati onoma,timh;
  FILE *fp;
  ptr1 =(int *)malloc(sizeof(int ) * 10);
  ptr  =(int *)malloc(sizeof(int )*10);
  for(i=0;i<10;i++)
  {
    ptr[i] = 100+rand()%898;
  }
  for(i=0;i<10;i++)
  {
    ptr1[i] = -100-rand()%-898;
  }
  num =(int *)malloc(sizeof(int )*20);
  for(i=0;i<10;i++)
  {
    num[i] = ptr[i];
  }
  for(i=10;i<20;i++)
  {
    num[i] = ptr[i-10];
  }
  free(ptr);
  free(ptr1);
  k = calc(num,20);
  printf("To apotelesma tis synartisis calc einai:%d",k);
  
  fp = fopen("numbers.txt","r");
  
  ptr =(int *)malloc(sizeof(int )*20);
  i=0;
  while(!feof(fp))
  {
    fscanf(fp,"%d",&x);
    ptr[i] = x;
	i++;
  }
  fclose(fp);
  k = calc(ptr,20);
  
  strcpy(onoma.a,"Random");
  timh.x = k;
  
  fp = fopen("results.dat","w");
  fprintf(fp,"%s %d",onoma.a,timh.x);
  fclose(fp);
  return 0;
}

int calc(int *num,int size)
{
  int i,count=0,count1=0;
  for(i=0;i<size;i++)
  {
    count += pow(num[i],2);
  }
  
  for(i=0;i<size;i++)
  {
    if(num[i]<0)
	{
	  num[i] *= -1;
	}
    count1 += num[i];
  }
  return count-size*count1;
}
