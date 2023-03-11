#include <stdio.h>
#define SIZE 20
int main(void)
{
  int N,a[SIZE],sum,i;
  printf("You can choose between 1-20\n");
  printf("How many cases do you want from the array?: \n");
  do
    scanf("%d",&N);
  while(N<1 || N>20);
  for(i=0;i<N;i++)
  {
    printf("Give me any number: ");
    scanf("%d",&a[i]);
    sum += a[i];
  }
    printf("The average of the array is: %.1f",(float)sum/N);
    return 0;








}
