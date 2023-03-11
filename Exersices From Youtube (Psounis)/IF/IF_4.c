#include <stdio.h>
int main(void)
{
  int x,wres,lepta,deut;
  printf("Eisagete plithos deuteroleptwn: ");
  scanf("%d",&x);
  wres = x/3600;
  x = x%3600;
  lepta = x/60;
  deut = x%60;
  printf("Wres:%d\n",wres);
  printf("Lepta:%d\n",lepta);
  printf("Deyterolepta:%d",deut);









}
