//This program tries to be a ATM!
#include <stdio.h>
#include <stdlib.h>

int digits(int PIN);           //Fuction that checks the digits of your PIN
float Deposit(int portfolio);  //Fuction that deposits the money to your bank account
char decision(void);           /*Fuction that questions the user if he wants 
                               to continue or end the program*/   
int checks(int portfolio);     //Checks the condition of user's bank account
void Goodbye(void);            //Goodbyes user
         



int main(void)
{ int PIN=0,tries = 1;
  printf("Type your four digits PIN\nYou have 3 tries!\n");
  while(PIN != 5090)                                                          //This piece of code checks the user's 
  {                                        
   int numb_dig=0;                                                           //PIN. The user's PIN must be a 4 digits
   printf("|%dst|: ",tries);                                                 //number and if he puts it incorrect more 
   while(numb_dig!=4)                                                        //than 4 times the program will terminate.
   {	                                                                      //This piece of code ends in the '!'.*/                                                                            
    scanf("%d",&PIN); 
    numb_dig = digits(PIN); 													//digits fuction checks the digits of the PIN
    if(numb_dig!=4)
      printf("Your PIN must be a four digits number!");                
   }
   if(PIN != 5090)
   {
	int count;
  if(tries == 1)
    count =1;
  else
    count += 1;
	tries += 1;                                                
	if(count == 3)
	{
	 printf("We must terminate your program for safety measures!\a");
	 exit(1);
    }
   }
  }                                         //!                    
  int portfolio = 0;                          
  char answ ='Y',deci = 0;                   //Opens the menu of the actions that the user
  while(answ == 'Y' || answ =='y')           //can choose and restricts them from choosing 
  {                                          //anything diffrent than the actions themselves
   deci = 0;                                  //This piece of code ends in the '!'.
   printf("\n");  
   printf("1.Withdrawal\n2.Deposit\n3.Balance Question\n4.Exit\n\n");
   do{
   	printf("I want to: ");
    scanf("%d",&deci);
   }while(deci != 1 && deci != 2 && deci != 3 && deci!= 4);  //!
   if(deci == 3)                                                     //Here the programm exits
   {                                                                 //The ammount of money that  
    printf("\n");                                                   //The user has at the moment
    printf("You have %d euros in your bank account\n\n",portfolio); //and asks them if they want to continue with the fuction decision                                                                    
	printf("Do you want to continue the transaction?\nY/N: ");      //This pieceof code ends in the '!'.         
    answ = decision();                                              
   }                                                                 //!                                              
   else if(deci == 2)                                                
   {                                                                     
    portfolio = Deposit(portfolio);                                        //Here the programm uses the Deposit fuction
	printf("\n");                                                          //To insert the amount of money that user selects                                                                               
    printf("Now you have %d euros in your bank account\n\n",portfolio);    //Into their bank account,then the programm prints
    printf("Do you want to continue the transaction?\nY/N: ");             //the new amount and then asks the user if he wants to continue using the fuction decision
    answ = decision();                                                     //This piece of code ends in the'!'.
    printf("Now you have %d euros in your bank account\n\n",portfolio); 
   }                                                                       //! 
   else if(deci == 1)                                                                            
   {
    int check = checks(portfolio);  //Here the programm checks in what situation the bank account is 
    if(check == 0)
	{
	 /*if the user doesnt have any money the programm updates them for the situation of their
	   bank account and then asks them if they want to continue using the fuction decision*/	
	 printf("\n");	
	 printf("You cant withdrawal because you dont have any amount of money in your bank account.\n\n");
	 printf("Do you want to continue the transaction?\nY/N: ");
	 answ = decision();
    }
    else if(check == 1)
    { /*if the user has lower than 20 euros the programm updates them for the situation of their
        bank account and then asks them if they wantto continue using the fuction decision*/
     printf("\n");
	 printf("You can withdrawal only amounts greater than 20 euros.\n\n");
	 printf("Do you want to continue the transaction?\nY/N: ");
	 answ = decision();
    }
    else if(check == 2) 
	{/*if the user has more than 20 euros in their bank account then the programm
	     tells and requires from the user to put an amount equal or greater than 20 
	     euros.Also the programm requires from the user to put an amount lower than their
	     amount of their bank account. Then the programm updates the user with their new
	     amount of money and at the end asks them if he wants to continue with the decision fuction*/
	 int out,o=0;
	 printf("\n");
	 printf("You must select an amount of money equal or greater than 20 euros.\n");
	 do{
	   o += 1;
	   if(o>1)
	   {
        if(out>portfolio)
		{
         printf("\n");
		 printf("You dont have %d euros. Actually you have %d euros\n",out,portfolio);
		}
 		else if(out<20)
 		{
 		 printf("\n");
		 printf("You must choose an amount equal or greater than 20 euros sir/madam!\n"); 
		}
	   }
	   printf("How much money do you want to deposit?: ");
	   scanf("%d",&out);
	 }while(out>portfolio || out<20); 
      portfolio -= out;
	  printf("\n");
	  printf("Now you have %d amount of money in your bank account\n",portfolio);
      printf("\n");
	  printf("Do you want to continue the transaction?\nY/N: "); 
      answ = decision();
    }
   else
	{ /*if the user has 20 euros in their bank account then the programm asks them
	     if they really want them to put it out.If their choose Y then the transaction
		 will be complete. Either way the programm asks the user if they want to continue
		 using the fuction decision*/	
	  char f = 'q';	
	  printf("Do you want to deposit your only 20 euros?\nY/N : ");
	  f = decision();
	  if(f == 'Y')
	  {
       portfolio -= 20;
	   printf("You have 0 euros in your bank account\n");   	  
	  }
	  printf("Do you want to continue the transaction?\nY/N: ");
	  answ = decision(); 
     }
    }
   else
  {
   Goodbye();   //If the user selects Exit them the programm will goodbye them with the Goodbye fuction and then terminate
   exit(1); 
  }
 }
 Goodbye();   //if the user selects to not continue from the decision fuction then the programm will goodbye using the Goodbye fuction them and then terminate
 return 0;
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




float Deposit(int portfolio)
{
  int money[6],position[6],p = 1,old_sum=0;
  char dec = 'q';
  position[0] = 5;
  position[1] = 10;
  position[2] = 20;
  position[3] = 50;
  position[4] = 100;
  position[5] = 200;
  position[6] = 500;
  printf("You can deposit amounts lower than 1000000 euros in total\n");
  printf("\n"); 
  for(int i=0;i<=6;i+=1)
  {
    printf("Deposit your %3d paper money: \t",position[i]);
    scanf(" %d",&money[i]);
  }
 printf("|============================================|\n");	
 printf("|      EUROS    |        USERS INPUT         |\n");
 printf("|---------------|----------------------------|\n");
 printf("|        5      |          %4d              |\n",money[0]);
 printf("|       10      |          %4d              |\n",money[1]);
 printf("|       20      |          %4d              |\n",money[2]);
 printf("|       50      |          %4d              |\n",money[4]);
 printf("|      200      |          %4d              |\n",money[5]);
 printf("|      500      |          %4d              |\n",money[6]);
 printf("|---------------|----------------------------|\n");
 printf("|      SUM      |         %6d             |\n",money[0] * 5 + money[1] * 10 + money[2] * 20 + money[3] * 50 + money[4] * 100 + money[5] * 200 + money[6] * 500);
 printf("|============================================|");
 printf("\n");
  portfolio += money[0] * 5 + money[1] * 10 + money[2] * 20 + money[3] * 50 + money[4] * 100 + money[5] * 200 + money[6] * 500;
  return portfolio;  
 }



int checks(int portfolio)
{ int check;
  if(portfolio == 0) 
    check = 0;
  else if(portfolio < 20)
    check = 1;
  else if(portfolio > 20)
    check = 2;
  else
    check = 3; 	    
  return check;
}




char decision(void)
{ 
  char x = 'q'; 
  while(x != 'Y' && x !='N' && x != 'n' && x!='y')
  {
   x = getchar();
  }
  return x; 
}




void Goodbye(void)
{
  printf("\n");
  printf("Thanks for your choosing our bank!\nHave a nice day!");
}
   
