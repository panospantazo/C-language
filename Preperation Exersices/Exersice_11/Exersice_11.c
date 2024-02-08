#include <stdio.h>
#include <stdlib.h>

int main(int argv,char*argc[])
{
	FILE *fp;
	char *ARR,*arr,let;
	int i;
	
	fp = fopen("file.txt","r");
	
	ARR = (char *)malloc(sizeof(char) * 26);	
	if(!ARR)
	{
		printf("Memory Problem");
		exit(EXIT_FAILURE);
	}
	
	arr = (char *)malloc(sizeof(char) * 26);	
	if(!arr)
	{
		printf("Memory Problem");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<26;i++)
	{
		arr[i] = 0;
		ARR[i] = 0;
	}
	
	while(!feof(fp))
	{
		let = fgetc(fp);
		if(let >= 'A' && let <= 'Z')
		{
			ARR[let-'A']+=1;
		}
		else if(let >= 'a' && let<= 'z')
		{
			arr[let-'a']+=1;
		}
	}
	
	printf("Syxnothta mikrwn xarakthrwn\n");
	printf("-----------------------------\n");
	for(i=0;i<26;i++)
	{
		printf("%c) emfanisthke %d fores\n",'a'+i,arr[i]);
	}
	
	printf("Syxnothta kefalaiwn xarakthrwn\n");
	printf("-----------------------------\n");
	for(i=0;i<26;i++)
	{
		printf("%c) emfanisthke %d fores\n",'A'+i,ARR[i]);
	}
	
	return 0;	
}
