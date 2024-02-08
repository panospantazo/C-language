#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argv,char *argc[])
{
	srand(time(NULL));
	int magic_number = 1+rand()%99,count=0,num;
		
	while(count<7)
	{
		printf("Dwse enan arithmo: ");
		scanf("%d",&num);
		if(num == magic_number)
		{
			printf("Nikhses!\n");
			printf("O magikos arithmos htan to %d\n",magic_number);
			count = 8;
		}
		count+=1;
	}
	if(count == 7)
	{
		printf("Exases!\n");
		printf("O magikos arithmos htan to %d\n",magic_number);
	}
	
	return 0;
}
