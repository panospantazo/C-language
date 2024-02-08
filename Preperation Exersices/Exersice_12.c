#include <stdio.h>
#include <stdlib.h>

struct proion{
	char kwd[100];
	char descr[100];
	float timh;
};

typedef struct proion PROION;

int main(int argv,char*argc[])
{
	FILE *fp;
	int N,i;
	PROION *arr;
	
	printf("Posa proionta thes:");
	scanf("%d",&N);
	
	arr = malloc(sizeof(PROION)*N);
	if(!arr)
	{
		printf("Memory Problem");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<N;i++)
	{
		printf("%do PROION!\n",i+1);
		printf("-----------\n");
		printf("Dwste thn timh toy proiontos:");
		scanf("%f",&arr[i].timh);
		printf("Dwste perigrafi proiontos: ");
		scanf("%s",&arr[i].descr);
		printf("Dwste ton kwdiko toy proiontos: ");
		scanf("%s",&arr[i].kwd);
		printf("\n");
	}
	
	fp = fopen("file.txt","w");
	if(!fp)
	{
		printf("Error opening the file.");
		exit(EXIT_FAILURE);
	}
	
	fprintf(fp,"%d\n",N);
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%.2f %s %s\n",i+1,arr[i].timh,arr[i].descr,arr[i].kwd);
	}
	
	
	free(arr);
	return 0;
}
