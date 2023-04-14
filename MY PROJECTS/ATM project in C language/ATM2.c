//This program tries to be an ATM
#include <stdio.h>
#include <stdlib.h>

int PIN_function();         //Checks if the PIN is right and the tries are below 3.
int digits(int);            //Fuction that checks how many digits your PIN have
int  Menu_Choice();			//Prints the main menu of the application		
int choice_check(int );		//Checks the users input
void Withdrawl();
void Deposit();
void Balance_Question();
void Exit();



int main(void)
{
  printf("Welcome to our bank's ATM machine!\n");
  printf("----------------------------------\n");
  if(!PIN_function())
  {
    printf("We must terminate your program for safety measures!\a");
	exit(1312);
  }
  while(1)
  {
    switch(Menu_Choice())
    {
  	  case(1):Withdrawl(); break;
  	  case(2):Deposit();  break;
  	  case(3):Balance_Question(); break;
  	  case(4):Exit(); exit(0);
    } 
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
 
int choice_check(int choice)
{
	while(choice >4 || choice <1)
	{
	  printf("Please press a number between 0-4\n");
	  printf("Your choice:");
	  scanf("%d",&choice);
	}
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

int Menu_Choice()
{
  int choice;
    printf("\n\n");
    printf("Welcome Customer\n");
    printf("What's your choice?\n");
    printf("-------------------\n");
    printf("1.Withdrawl\n");
    printf("2.Deposit\n");
    printf("3.Balance Question\n");
    printf("4.Exit\n");
    printf("Your choice:");
    scanf("%d",&choice);
    choice_check(choice);
    return choice;  
}

void Withdrawl()
{
	printf("\nola kala\n");
}

void Deposit()
{
	printf("\nola kala\n");
}

void Balance_Question()
{
	printf("\nola kala\n");
}

void Exit()
{
   printf("\n");
   printf("Thanks for your choosing our bank!\n");
   printf("Have a nice day!\n");
}
