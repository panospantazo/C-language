#include <stdio.h>
#include <stdlib.h>

int main(int argv,char*argc[])
{
	int count=0,i;
	char let,*arr;
	FILE *fp;
	
	fp = fopen("file.txt","r");
	if(!fp)
	{
		printf("Error opening the file!\n");
		exit(EXIT_FAILURE);
	}
	
	arr = (char *)malloc(sizeof(char)*26);
	if(!arr)
	{
		printf("Memory Problem!");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<26;i++)
	{
		arr[i] = 0;
	}
	
	while(!feof(fp))
	{
		let = fgetc(fp);
		if(let >= 65 && let <= 90)
		{
			arr[let-'A']+=1;
		}
		else if(let >= 'a' && let <= 'z')
		{
			count+=1;	
		}
		
	}
	
	printf("To arxeio eixe %d oxi kefalaious xarakthres\n",count);
	for(i=0;i<26;i++)
	{
		printf("%c) emfanisthke %d fores\n",'A'+i,arr[i]);
	}
	
	free(arr);
	return 0;
}
