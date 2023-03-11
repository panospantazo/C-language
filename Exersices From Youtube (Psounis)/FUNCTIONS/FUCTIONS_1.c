#include <stdio.h>

int get_integer(int start,int finish);

int main(void)
{
  int a,b,n;
  printf("1)Dwse to a: \n");	
  a = get_integer(1,10);
  printf("2)Dwse to b: \n");
  b = get_integer(1,10);
  printf("Dwse to n: \n");
  n = get_integer(2,5);
  printf("%d*(%d-%d)=%d",n,a,b,n*(a-b));
  return 0;
}


int get_integer(int start,int finish)
{
  int x;	
  do{
    printf("Dwse moy enan arithmo sto diasthma %d ews %d: ",start,finish);
    scanf("%d",&x);
  }while(x>finish || x<start);
  return x;  
}


