#include <stdio.h>
#include <stdlib.h>
									//65-90

int * Frequency(char arr[],int SIZE);

int main(int argv,char *argc[])
{
	char *arr;
	int i,*fr,SIZE;	
	
	printf("Posa grammata thelete na exei mesa o pinakas: ");
	scanf("%d",&SIZE);
	
	arr = (char *) malloc(sizeof(char) * SIZE);
	if(!arr)
	{
		printf("Memory Problem!");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<SIZE;i++)
	{
		printf("Dwste to %do gramma: ",i+1);
		scanf(" %c",&arr[i]);
	}
	
	fr = Frequency(arr,SIZE);
	
	for(i=0;i<26;i++)
	{
		printf("%c)%d\n",i+65,fr[i]);
	}
	
	free(arr);
	free(fr);
	return 0;
}

int * Frequency(char arr[],int SIZE)
{
	int *fr;
	int i;
	
	fr = (int *) malloc(sizeof(int) * 26);
	if(!fr)
	{
		printf("Memory Problem");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<26;i++)
	{
		fr[i] = 0;
	}
	
	
	
	for(i=0;i<SIZE;i++)
	{
		fr[(int)arr[i]-65]+=1;
	}
	
	return fr;
}
