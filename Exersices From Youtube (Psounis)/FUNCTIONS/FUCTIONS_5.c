#include <stdio.h>

int mkd(int,int);

main(void)
{
  int a,b,res;	
  printf("Dwse ton prwto arithmo: ");
  scanf("%d",&a);
  printf("Dwse ton deutero arithmo: ");
  scanf("%d",&b);	
  res = mkd(a,b);
  printf("\nO MKD EINAI O %d",res);
 
}

int mkd(int n,int n1)
{
  printf("\n%d %d",n,n1);	
  if(n == n1)
    return n;
  else if(n<n1)
    mkd(n,n1-n);
  else if(n>n1)
    mkd(n-n1,n1);	  
}
