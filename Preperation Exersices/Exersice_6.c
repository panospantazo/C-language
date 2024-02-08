#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 5

void change(char arr[]);

int main(int argv,char *argc[])
{
	int i;
	char *arr;
	
	arr = malloc(sizeof(char) * 5);
	if(!arr)
	{
		printf("Memory Problem\n");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<SIZE;i++)
	{
		arr[i] = (char)(i+65);
	}
	
	//char ar[]={'!','a','B'};
		
	change(arr);
	
	for(i=0;i<SIZE;i++)
	{
		printf("%c\n",arr[i]);
	}
	
	free(arr);
	
	
	return 0;
}

void change(char arr[])
{
	int i;
	
	for(i=0;i<SIZE;i++)
	{
		if(islower(arr[i]))
		{
			arr[i] = toupper(arr[i]);
		}
		else if(isupper(arr[i]))
		{
			arr[i] = tolower(arr[i]);
		}
	}
}
