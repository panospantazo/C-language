//This program tries to be an ATM
#include <stdio.h>
#include <stdlib.h>

int PIN_function();         //checks if the PIN is right and the tries are below 3.
int digits(int);            //Fuction that checks how many digits your PIN have


int main(void)
!FILE *p
{
  printf("Welcome to our bank's ATM machine!\n");
  printf("----------------------------------\n");
  if(!PIN_function())
  {
   printf("We must terminate your program for safety measures!\a");
	 exit(230);
  }
  
  return 0; 
}

int PIN_function()
{
    int numb_dig=0,PIN=0,tries = 1;
    printf("Type your four digits PIN\nYou have 3 tries!\n");
    while (PIN != 5090 && tries != 4)
    {
        if(tries>1)
        {
            printf("Type your four digits PIN again!\n");
        }                                                                                                                          
        printf("|%dst|: ",tries);                                                                                                                                                                                                                   
        scanf("%d",&PIN);
        numb_dig = digits(PIN); 													
        while(numb_dig != 4)
        {
            printf("Your PIN must be a four digits number!\n");
            printf("|%dst|: ",tries);
            scanf("%d",&PIN);
            numb_dig = digits(PIN);
        }                    
        if(PIN != 5090)
        {
            tries += 1;   
        }                                               
    }
    if(tries > 3)
      return 0;
    else 
      return 1;
}
 

int digits(int PIN)
{  
  int count = 0;
  while(PIN!=0)  
    {  
        PIN=PIN/10;  	
        count += 1;  
    }  
    return count; 
}