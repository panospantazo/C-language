#include <stdio.h>
int main(void)
{
  int dice1,dice2,sumA=0,sumB=0;
  
  //PAIXTHS A
  printf("Zari 1o paixth A: ");
  scanf("%d",&dice1);
  printf("\nZari 2o paixth A: ");
  scanf("%d",&dice2);
  sumA = dice1 + dice2;
  
  //PAIXTHS B
  printf("\nZari 1o paixth B: ");
  scanf("%d",&dice1);
  printf("\nZari 2o paixth B: ");
  scanf("%d",&dice2);
  sumB = dice1 + dice2;
  
  //ELEXGOS  
  if(sumA>sumB)
    printf("O paixths A nikhse!");
  else if(sumB>sumA)
    printf("O paixths B nikhse!");
  else
    printf("Isopalia!");  
  return 0;  
}
