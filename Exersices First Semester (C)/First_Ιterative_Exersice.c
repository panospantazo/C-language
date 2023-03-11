#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100

float stdev(float *);
float average(float *);

int main(void)
{
 int i;
 float *num,s,ave,count=0,count1=0;
 FILE *fp;
 srand(time(NULL));
 num =(float*)malloc(sizeof(float )*N);
 if(num == NULL)
 {
   printf("Adynamia desmeusis mnimis!\n");
   exit(525);
 }
 for(i=0;i<N;i++)
 {
   num[i] = 25+rand()%26;
 }
 s = stdev(num);
 ave = average(num);
 for(i=0;i<N;i++)
 {
   if(ave + s < num[i] && ave + (2*s) > num[i])
   {
     count++;
   }
   if(ave - s < num[i] && ave - (2*s) > num[i])
   {
     count1++;
   }
 }
 count = count/N;
 count1 = count1/N;
 
 printf("average %c stdev:%.2f%%  | average %c 2*stdev:%.2f%%",241,count,241,count1);
 fp = fopen("percent.dat","w");
 if(fp == NULL)
 {
   printf("Adynamia anoigmatos arxeioy\n");
   exit(725);
 }
 fprintf(fp,"average %c stdev:%.2f%%  | average %c 2*stdev:%.2f%%",241,count,241,count1);
 free(num);
 fclose(fp);
 return 0;
}

float stdev(float *num)
{
  int i;
  float ave,numerator=0,denominator=0;
  ave = average(num);
  for(i=0;i<N;i++)
  {
    numerator += pow(num[i] - ave,2);
  }
  denominator = N - 1;
  return sqrt(numerator/denominator);
}

float average(float *num)
{
  int i;
  float average,sum=0;
  for(i=0;i<N;i++)
  {
    sum += num[i];
  }
  average = sum/N;
  return average;
}
