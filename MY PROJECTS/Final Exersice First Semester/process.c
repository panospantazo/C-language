#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define NUM_CANDIDATES 7
#define COLLUMS 3
#define FILES "voters.dat"





int count_voters(); //������ ������� �����
int convert_age(unsigned short int ); //��������� ������������ �� ������
int convert_gender(unsigned short int ); //��������� ������������ �� ���� 
int convert_vote(unsigned short int );   //��������� ������������ �� ����
void filling_voters_array(int **,int );   //������� ��� ������ ��� ���������
void filling_candidates_gender_array(unsigned int **,int ** ,int); //������� ��� ������ ��� ��������� ������� �� ����
void filling_candidates_age_array(int **,int **,int); //������� ��� ������ ��� ��������� ������� ��� ������
int find_max_candidate(int **,int); //������ ��������� �� ���� ������������� ������
int find_max_gender_man_candidate(unsigned int **,int); //������ ��������� �� ��� ������������ �������� ������
int find_max_gender_woman_candidate(unsigned int **,int); //������ ��������� �� ��� ������������ ���������� ������
int find_max_gender_allo_candidate(unsigned int **,int);  //������ ��������� �� ��� ������������ ����� ������
int count_18_29_voters(int **,int );                      //������ ������� ��������� ������� 18-27
int count_30_44_voters(int **,int);                       //������ ������� ��������� ������� 30-44
int count_45_59_voters(int **,int);                       //������ ������� ��������� ������� 45-59
int count_60_voters(int **,int);                          //������ ������� ��������� ������� ��� 60 ��� ����
int max_youth(int **);                                    //������ �������� ��������� ��� ��� �������
int max_elder(int **);                                    //������ �������� ��������� ��� ���� �������������
void print_histogram_man_gender(unsigned int **,int );    //�������� ������������� ��� ����� ��� ������ ��� ���� ��������
void print_histogram_woman_gender(unsigned int **,int );  //�������� ������������� ��� ����� ��� �������� ��� ���� ��������
void print_histogram_allo_gender(unsigned int **,int );   //�������� ������������� ��� ����� ��� '����' ��� ���� ��������
void print_histogram_overall_votes(int **,int );          //�������� ������������� ��� ��������� ����� ��� ���� ��������







int main(void)
{
  int i,j,valid_voters,**voters,**num_candidates_age,man,woman,allo,max_candidate;
  int count_18_29,count_30_44,count_45_59,count_60,youth,elder;
  unsigned int **num_candidates;	
  
  valid_voters = count_voters();
    
  //�������� ����� ��� ����������� ������ ���������
  
  voters = (int **)malloc(sizeof(int*)*valid_voters);
  if(!voters)
  {
  	printf("Adynamia desmeusis mnimis!\n");
    exit(200);
  }
  for(i=0;i<valid_voters;i++)
  {
    voters[i] = (int *)malloc(sizeof(int) * COLLUMS);
     if(!voters[i])
     {
       printf("Adynamia desmeusis mnimis!\n");
       exit(200);
     }
  }
  
  //������� ������������ ��� ������ ��� ���������
  filling_voters_array(voters,valid_voters);
  
  //�������� ����� ��� ����������� ������ ��������� ������� �� ����
  
  num_candidates =(unsigned int **) malloc(sizeof(unsigned int*)*NUM_CANDIDATES);
  if(!num_candidates)
  {
  	printf("Adynamia desmeusis mnimis!\n");
    exit(200);
  }
  for(i=0;i<NUM_CANDIDATES;i++)
  {
     num_candidates[i] =(unsigned int *) malloc(sizeof(unsigned int) * COLLUMS);
     if(!num_candidates[i])
     {
       printf("Adynamia desmeusis mnimis!\n");
       exit(200);
     }
  }
  
  //������� ��� ������������ ������ ��� ��������� ������� �� ����
  filling_candidates_gender_array(num_candidates,voters,valid_voters);
  
  //�������� ����� ��� ����������� ������ ��������� ������� ��� ������
  
  num_candidates_age = (int **)malloc(sizeof(int*)*NUM_CANDIDATES);
  if(!num_candidates_age)
  {
  	printf("Adynamia desmeusis mnimis!\n");
    exit(200);
  }
  for(i=0;i<NUM_CANDIDATES;i++)
  {
     num_candidates_age[i] = (int *) malloc(sizeof(unsigned int) * 4);
     if(!num_candidates_age[i])
     {
       printf("Adynamia desmeusis mnimis!\n");
       exit(200);
     }
  }
  
  //������� ��� ������ ��� ��������� ������� ��� ������
  filling_candidates_age_array(num_candidates_age,voters,valid_voters);
  
  //������� ��� ���������� 
  max_candidate = find_max_candidate(voters,valid_voters);
  man = find_max_gender_man_candidate(num_candidates,valid_voters);
  woman = find_max_gender_woman_candidate(num_candidates,valid_voters);
  allo = find_max_gender_allo_candidate(num_candidates,valid_voters);
  youth = max_youth(num_candidates_age);
  elder = max_elder(num_candidates_age);
  
  count_18_29 = count_18_29_voters(voters,valid_voters);
  count_30_44 = count_30_44_voters(voters,valid_voters);
  count_45_59 = count_45_59_voters(voters,valid_voters);
  count_60 = count_60_voters(voters,valid_voters);
  
    
  //���������� 
  
  print_histogram_man_gender(num_candidates,valid_voters);
  print_histogram_woman_gender(num_candidates,valid_voters);
  print_histogram_allo_gender(num_candidates,valid_voters);
  print_histogram_overall_votes(num_candidates_age,valid_voters);
 
  printf("\n\n\n\n\n\n\n");
  printf("                                                          ----------------\n");
  printf("                                                          |PINAKAS PSIFWN|\n");
  printf("                                                          ----------------\n");
  printf("|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|\n");
  printf("|      MAXIMUM        |    MAXIMUM ANTRES   |  MAXIMUM GYNAIKES   |   MAXIMUM ALLO      | MAXIMUN NEOLAIA     |MAXIMUM HLIKIWMENOI  |\n");
  printf("|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|\n");
  printf("|      %dos(%2d)        |       %dos(%2d)       |       %dos(%2d)       |        %dos(%2d)      |        %dos(%2d)      |       %dos(%2d)       |\n",max_candidate,num_candidates[max_candidate-1][0]+num_candidates[max_candidate-1][1]+num_candidates[max_candidate-1][2],find_max_gender_man_candidate(num_candidates,valid_voters),num_candidates[man-1][0],find_max_gender_woman_candidate(num_candidates,valid_voters),num_candidates[woman-1][1],find_max_gender_allo_candidate(num_candidates,valid_voters),num_candidates[allo-1][2],youth,num_candidates_age[youth-1][0],elder,num_candidates_age[elder-1][3]);
  printf("|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|\n");
  
  printf("\n\n\n\n\n");
  
 
  printf("                                                          -----------------\n");
  printf("                                                          |PINAKAS PLHTHWN|\n");
  printf("                                                          -----------------\n");
  printf("                                               |---------|---------|---------|-------|\n");
  printf("                                               |  18-29  |  30-44  |  45-59  |  60<  |\n");
  printf("                                               |---------|---------|---------|-------|\n");
  printf("                                               |   %3d   |   %3d   |   %3d   |  %3d  |\n",count_18_29,count_30_44,count_45_59,count_60);
  printf("                                               |---------|---------|---------|-------|\n");
  
  
  //������������ ������� 
  for(i=0;i<NUM_CANDIDATES;i++)
    free(num_candidates_age[i]);
  free(num_candidates_age);
  
  for(i=0;i<NUM_CANDIDATES;i++)
    free(num_candidates[i]);
  free(num_candidates);  
  
  for(i=0;i<valid_voters;i++)
    free(voters[i]);
  free(voters);
  
  return 0;
}


int count_voters()
{
  unsigned short int hex;	
  int valid_voters , age , gender , vote, test1,test2,test3;
  //������� ������� ���������
  
  FILE *fvoters;
  
  fvoters = fopen(FILES,"r");
  if(fvoters == NULL)
  {
    printf("Adynamia anoigmatos toy arxeioy!\n");
    exit(666);
  }
  valid_voters = 0;
  
  while(fscanf(fvoters,"%x",&hex) != EOF)
  {
  	  //��������� ������������ �� ������,���� ��� ����
      age = convert_age(hex);
      gender = convert_gender(hex);
      vote = convert_vote(hex);
      
	  test1 = FALSE;
	  test2 = FALSE;
	  test3 = FALSE; 
      
	  //������� ����������� �����
	  if(age >= 18 && age <= 99)
        test1 = TRUE;
      if(gender == 1 || gender == 2 || gender == 3)
	    test2 = TRUE;
	  if (vote==0 || vote==1 || vote==2 || vote==4 || vote==8 || vote==16 || vote==32 || vote==64)
	    test3 = TRUE;
	  if(test1 == TRUE && test2 == TRUE && test3 == TRUE)
	    valid_voters++;	      
  }
  fclose(fvoters);
  return(valid_voters); 
}




int convert_age(unsigned short int hex)
{
  int age;
  /*������ ��������� �� ����� ��� �������� �� ��� ����� ��� ������ �� ���� �������� ���� �� ����� ���� �� ����������� � ����� ���� ���� ���������*/	
  age = (hex & 0xfe00) >> 9;
  return age;
}




int convert_gender(unsigned short int hex)
{
  int gender;
  /*������ ��������� �� ����� ��� �������� �� ��� ����� ��� ������ �� ���� �������� ���� �� ����� ���� �� ����������� � ����� ���� ���� ���������*/	
  gender = (hex & 0x0180) >> 7;
  return gender;
}




int convert_vote(unsigned short int hex)
{
  int vote;
  /*�������� ��� ����� ��� ����� ��� ���������� ���� �� �� ��������� ��� �� �� ���������� ��� ��������� �����������*/
  vote = hex & 0x7f;
  return(vote);
}




void filling_voters_array(int **voters,int valid_voters)
{	
 int i=0,hex,test1,test2,test3;
 
 //������� ������� ���������
 
 FILE *fvoters;
  
  
  fvoters = fopen(FILES,"r");
  if(fvoters == NULL)
  {
    printf("Adynamia anoigmatos toy arxeioy!\n");
    exit(666);
  }
  
  while(fscanf(fvoters,"%x",&hex) != EOF && i<valid_voters)
  {
  	  
	  //��������� ������������ �� ������,���� ��� ����
      int age = convert_age(hex);
      int gender = convert_gender(hex);
      int vote = convert_vote(hex);
      
	  test1 = FALSE;
	  test2 = FALSE;
	  test3 = FALSE; 
      
	  //������� ����������� �����
	  if(age >= 18 && age <= 99)
        test1 = TRUE;
      if(gender == 1 || gender == 2 || gender == 3)
	    test2 = TRUE;
	  if (vote==1 || vote==2 || vote==4 || vote==8 || vote==16 || vote==32 || vote==64 )
	  {
	    test3 = TRUE;
      }
	    
	  //�� �� test ��� ����� TRUE ���� � ����� ��� ����� ������ ��� ��� ������������ ���� ������ voters  
	  if(test1 == TRUE && test2 == TRUE && test3 == TRUE)
	  {
	    voters[i][0] = age;
	    voters[i][1] = gender;
	    switch(vote)
		{
		case 1: voters[i][2] = 1; break;
		case 2: voters[i][2] = 2; break;
		case 4: voters[i][2] = 3; break;
		case 8: voters[i][2] = 4; break;
		case 16: voters[i][2] = 5; break;
		case 32: voters[i][2] = 6; break;
		case 64: voters[i][2] = 7; break;
		}
	   i++;		
	  }    	      
  }
  fclose(fvoters);  
}




void filling_candidates_gender_array(unsigned int **num_candidates,int **voters,int valid_voters)
{
  int i,j;
  
  //������������ ������������ ������ ��� ��������� ������� �� ����
  
  for(i=0;i<NUM_CANDIDATES;i++)
  {
   for(j=0;j<=2;j++)
   {
     num_candidates[i][j] = 0;
   }
  }
  
  //������� ������������ ������ ��� ��������� ������� �� ����
  
  for(i=0;i<valid_voters;i++)
  {
   for(j=0;j<=6;j++)
   {
    if(voters[i][2] == j+1)
	{
	 if(voters[i][1] == 1)
	   num_candidates[voters[i][2]-1][0] += 1; 
	 else if(voters[i][1] == 2)
	   num_candidates[voters[i][2]-1][1] += 1;
	 else if(voters[i][1] == 3)
	   num_candidates[voters[i][2]-1][2] += 1; 
	}
   }
  }
}




void filling_candidates_age_array(int **num_candidates_age,int **voters,int valid_voters)
{
  	int i,j;
  
  //������������ ������������ ������ ��� ��������� ������� ��� ������ 
  
  for(i=0;i<NUM_CANDIDATES;i++)
  {
   for(j=0;j<=3;j++)
   {
     num_candidates_age[i][j] = 0;
   }
  }
  
  //������� ������������ ������ ��� ��������� ������� ��� ������
  
  for(i=0;i<valid_voters;i++)
  {
   for(j=1;j<=7;j++)
   {
    if(voters[i][2] == j)
	{
	 if(voters[i][0] <= 29)
	   num_candidates_age[voters[i][2]-1][0] += 1; 
	 else if(voters[i][0]<= 44)
	   num_candidates_age[voters[i][2]-1][1] += 1;
	 else if(voters[i][0] <= 59)
	   num_candidates_age[voters[i][2]-1][2] += 1;
	 else if(voters[i][0]>59 && voters[i][0]<99)
	   num_candidates_age[voters[i][2]-1][3] += 1; 
	}
   }
  }
}




int find_max_candidate(int **voters,int valid_voters)
{
  int *ptr,i,j,max,u_max,count;
  
  //�������� �����, ������������ ��� ������� ���� ������ ��������
  
  ptr = (int *)malloc(sizeof(int) * 7);
  
  for(i=0;i<NUM_CANDIDATES;i++)
     ptr[i] = 0;
  
  for(i=0;i<valid_voters;i++)
  {
  	for(j=1;j<=NUM_CANDIDATES;j++)
	{
    if(voters[i][2] == j)
      ptr[j-1] += 1;
	}
  }
  
  //������ max ��� ��� ������ ��������
  
  max = ptr[0];
  u_max = 0;
  for(i=1;i<NUM_CANDIDATES;i++)
  {
    if(max<ptr[i])
    {
      max = ptr[i];
      u_max = i+1;
    }
  }
  free(ptr);
  if(u_max == 0)
    return 1;
  return u_max;
}




int find_max_gender_man_candidate(unsigned int **num_candidates,int valid_voters)
{
  int i;
  
  //������ max ��� ��� ����� ����� ��� ������������ ������ ��������� ������� �� ����
  	
  int max =num_candidates[0][0];
  int u_max = 0;
  for( i=1;i<NUM_CANDIDATES;i++)
  {
    if(max<num_candidates[i][0])
	{
      max = num_candidates[i][0];
      u_max = i+1;
    }
  } 
  if(u_max == 0)
    return 1;
  return u_max;
} 




int find_max_gender_woman_candidate(unsigned int **num_candidates,int valid_voters)
{
  int i;
  
  //������ max ��� ��� ������� ����� ��� ������������ ������ ��������� ������� �� ����
  
  int max = num_candidates[0][1];
  int u_max = 0;
  for(int i=1;i<NUM_CANDIDATES;i++)
  {
    if(max<num_candidates[i][1])
	{
      max = num_candidates[i][1];
      u_max = i+1;
    }
  } 
  if(u_max == 0)
    return 1;
  return u_max;
}




int find_max_gender_allo_candidate(unsigned int **num_candidates,int valid_voters)
{
  int i;
  
  //������ max ��� ��� ���������� ��� ������������ ������ ��������� ������� �� ����
  
  int max =num_candidates[0][2];
  int u_max = 0;
  for(int i=1;i<NUM_CANDIDATES;i++)
  {
    if(max<num_candidates[i][2])
	{
      max = num_candidates[i][2];
      u_max = i+1;
    }
  } 
  if(u_max == 0)
    return 1;
  return u_max;
}




int count_18_29_voters(int **voters,int valid_voters)
{
  int i,count=0;

  for(i=0;i<valid_voters;i++)
  {
     if(voters[i][0]>=18 && voters[i][0] <=29)
	   count++; 
  }
  return count;
}





int count_30_44_voters(int **voters,int valid_voters)
{
  int i,count=0;

  for(i=0;i<valid_voters;i++)
  {
     if(voters[i][0]>=30 && voters[i][0] <=44)
	   count++; 
  }
  return count;
}




int count_45_59_voters(int **voters,int valid_voters)
{
  int i,count=0;

  for(i=0;i<valid_voters;i++)
  {
     if(voters[i][0]>=45 && voters[i][0] <=59)
	   count++; 
  }
  return count;
}




int count_60_voters(int **voters,int valid_voters)
{
   int i,count=0;

  for(i=0;i<valid_voters;i++)
  {
     if(voters[i][0]>=60)
	   count++; 
  }
  return count;
}





int max_youth(int **num_candidates_age)
{
  int i,max,u_max;
  
   //������ max ��� ��� ����� ����� ��� ������������ ������ ��������� ������� ��� ������
  
  max = num_candidates_age[0][0];
  u_max = 1;
  for(i=1;i<=6;i++)
  { 
   if(num_candidates_age[i][0] > max)
   {
     max = num_candidates_age[i][0];
     u_max = i+1;
   }
  } 
  if(u_max == 0)
    return 1;
  return u_max;
}




int max_elder(int **num_candidates_age)
{
  int i,max,u_max;
  
   //������ max ��� ��� ������� ����� ��� ������������ ������ ��������� ������� �� ����
  
  max = num_candidates_age[0][3];
  u_max = 1;
  for(i=1;i<=6;i++)
  { 
   if(num_candidates_age[i][3] > max)
   {
     max = num_candidates_age[i][3];
     u_max = i+1;
   }
  } 
  if(u_max == 0)
    return 1;
  return u_max;	
}




void print_histogram_man_gender(unsigned int **num_candidates,int valid_voters)
{
  int i, j;	
  
  int *ptr;	
  printf("|-----------------------------------|\n");
  printf("|Istogramma gia tis antrikes psifous|\n");
  printf("|-----------------------------------|\n");
  ptr =(int *) malloc(sizeof(int) * 7);
  for(i=0;i<=6;i++)
  {
    ptr[i] = i+1;
  }  
  for (i = 0; i <= 6; i++) 
  {
    printf("%dos: ",ptr[i]);
     for (j = 0; j < num_candidates[i][0]; j++) 
	 {
        printf("*");
     }
        if(num_candidates[i][0] != 0)
          printf(" [%d]",num_candidates[i][0]);
        printf("\n");
  }  
  free(ptr);
}




void print_histogram_woman_gender(unsigned int **num_candidates,int valid_voters)
{
  int i, j;	
  printf("\n\n\n\n\n");
  int *ptr;	
  printf("|--------------------------------------|\n");
  printf("|Istogramma gia tis gunaikeies psifous |\n");
  printf("|--------------------------------------|\n");
  ptr =(int *) malloc(sizeof(int) * 7);
  for(i=0;i<=6;i++)
  {
    ptr[i] = i+1;
  }  
  for (i = 0; i <= 6; i++) 
  {
    printf("%dos: ",ptr[i]);
     for (j = 0; j < num_candidates[i][1]; j++) 
	 {
        printf("*");
     }
      if(num_candidates[i][1] != 0)
          printf(" [%d]",num_candidates[i][1]);
      printf("\n");
  }  
  free(ptr);
}




void print_histogram_allo_gender(unsigned int **num_candidates,int valid_voters)
{
  int i, j;	
  printf("\n\n\n\n\n");
  int *ptr;	
  printf("|-----------------------------------|\n");
  printf("|Istogramma gia tis 'allo' psifous  |\n");
  printf("|-----------------------------------|\n");
  ptr =(int *) malloc(sizeof(int) * 7);
  for(i=0;i<=6;i++)
  {
    ptr[i] = i+1;
  }  
  for (i = 0; i <= 6; i++) 
  {
    printf("%dos: ",ptr[i]);
     for (j = 0; j < num_candidates[i][2]; j++) 
	 {
        printf("*");
     }
       if(num_candidates[i][2] != 0)
        printf(" [%d]",num_candidates[i][2]);
       printf("\n");
  }  
  free(ptr);
}




void print_histogram_overall_votes(int **num_candidates_age,int valid_voters)
{
  int i, j;	
  printf("\n\n\n\n\n");
  int *ptr,*ptr1;	
  printf("|------------------------------------------------------|\n");
  printf("|Istogramma gia tis sinolikes psifous kathe ipopsifiou |\n");
  printf("|------------------------------------------------------|\n");
  ptr =(int *) malloc(sizeof(int) * 7);
  for(i=0;i<=6;i++)
  {
    ptr[i] = i+1;
  }  
  ptr1 = (int *) malloc(sizeof(int) *7);
  for(i=0;i<=6;i++)
  {
    ptr1[i] = num_candidates_age[i][0] + num_candidates_age[i][1] + num_candidates_age[i][2] + num_candidates_age[i][3];
  }
  for (i = 0; i <= 6; i++) 
  {
    printf("%dos: ",ptr[i]);
    for (j = 0; j < ptr1[i]; j++) 
	{
      printf("*");
    }
      if(ptr1[i] != 0)
        printf(" [%d]",ptr1[i]); 
      printf("\n");
  }  
  free(ptr);
  free(ptr1);
}
