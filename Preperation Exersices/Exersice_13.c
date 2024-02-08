#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int luck(int x,int y);

int main(int argv,char *argc[])
{
	int x,y,i;
	srand(time(NULL));
	
	printf("Dwse to panw orio: ");
	scanf("%d",&x);
	
	printf("Dwse to katw orio: ");
	scanf("%d",&y);
	while(y>=x)
	{
		printf("Xanadwse arithmo den ginetai to katw orio>=panw orioy: ");
		scanf("%d",&y);
		printf("\n");
	}
	
	for(i=0;i<5;i++)
	{
		printf("%dos tyxaios arithmos: %d\n",i+1,luck(x,y));
	}
	
	return 0;
}

int luck(int x,int y)
{
	return y+rand()%(x-(y+1));
	
}
