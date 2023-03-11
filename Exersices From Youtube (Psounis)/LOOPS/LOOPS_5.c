#include <stdio.h>
int main(void)
{
  int N,a[20],i,min;
  printf("Give me a number between 2-20: ");
  do
    scanf("%d",&N);
  while(N<2 || N>20);
  for(i=0;i<N;i++)
  {
    printf("Give me any number: ");
	scanf("%d",&a[i]);  
  }
  min = a[0];
  for(i=1;i<N;i++)
  {
    if(min>a[i])
      min = a[i];
  }
  printf("%d",min);
  return 0;

}
