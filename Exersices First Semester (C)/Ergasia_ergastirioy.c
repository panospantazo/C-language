#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
  int dice1,dice2,lower=1,upper=8;
  printf("Roll The Dice!\n");
  
  srand(time(NULL)); 
  dice1 = rand() % (upper - lower);
  printf("1st Dice: %d\n",dice1);
  dice2 = rand() % (upper - lower);
  printf("2st Dice: %d",dice2);
  return 0;
}
