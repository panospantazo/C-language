#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Letters 26

/*Συναρτήσεις που τερματίζουν το πρόγραμμα ανάλογα το λάθος*/
void print_error_parameteres();
void print_error_file_input_message(int **lineNumber,FILE *fp);
void print_error_file_message(FILE *fp);
void print_error_allocating_memory_message();

/*Η κύρια συνάρτηση που επεξεργάζεται το αρχείο σύμφωνα με τα ζητούμενα της άσκησης*/
void process_file(const char *);

/*Malloc και free στον πίνακα γραμμάτων με 26 θέσεις με πρώτη θέση το 'Α' και τελευταία το 'Z'*/
char* array_allocation_letters();
void array_deallocation_letters(char *letters);

																				             /*Σε κάθε δέσμευση πίνακα βάζω ως όρισμα και τους προηγούμενους που έχουν
																							  δεσμευτεί, ώστε άμα υπάρξει κάποιο πρόβλημα στη μνήμη να κάνω free όσους
																							   έχω ήδη δεσμεύεσει*/ 
/*Malloc και free στον δισδιάστατο πίνακα που περιέχει τις λέξεις του αρχείου*/																							 
char** array_allocation_words(int count,int max_length,const char *filename);
void array_deallocation_words(char **words,int max_length);

/*Malloc και free στον πίνακα που περιέχει την συχνότητα του κάθε γράμματος*/
int* array_allocation_frequency_letters(char **words,int max_length);
void array_deallocation_frequency_letters(int *letters);

/*Οι δύο παρακάτω συναρτήσεις μετρούν την μεγαλύτερη λέξη και την πιο μεγάλη λέξη ώστε να μπορώ να δεσμεύσω σωστά τον πίνακα που περιέχει τις λέξεις του αρχείου*/
int count_words(const char *filename);
int find_max_length(const char *filename);

/*Η συνάρτηση ελέγχει άμα το αρχείο πληροί τις προυποθέσεις*/
int Check_characters(const char *filename,int max_length,int **lineNumber);

/*Η συνάρτηση μετράει το πλήθος του κάθε γράμματος και τα αποθηκεύει στον πίνακα που περιέχει την συχνότητα του κάθε γράμματος*/
int* count_letter_frequency(char **words, int *letters,int count,int max_length);

/*Η συνάρτηση εκτυπώνει το πόσες φορές έχει εμφανιστεί κάθε γράμμα*/
void print_letter_frequency(int *frequency_letters,char *letters);

/*Η συνάρτηση εκτυπώνει τα ζευγάρια των 5 πιο συχνών γραμμάτων*/
void print_combinations(int *frequency_letters,char **words,int max_length,char *letters);


int main(int argc,char*argv[])
{

	if (argc != 2) 
	{
        print_error_parameteres();
    }

	process_file(argv[1]);

	return 0;
}

void print_error_parameteres()
{
	printf("Invalid number of parameters\n");
	exit(EXIT_FAILURE);
}

void print_error_file_input_message(int **lineNumber,FILE *fp)
{
	printf("Invalid Data in Line %07d\n",**lineNumber);
	fclose(fp);
	exit(EXIT_FAILURE);
}	

void print_error_message(FILE *fp)
{
	printf("Cannot read input file\n");
	fclose(fp);
	exit(EXIT_FAILURE);
}

void print_error_allocating_memory_message()
{
	printf("Memory Problem\n");
	exit(EXIT_FAILURE);
}

char** array_allocation_words(int count,int max_length,const char *filename)
{
		int i;
		char **words;
		
		words = (char**)malloc(count * sizeof(char*));
    	if (!words) 
		{
    	    print_error_allocating_memory_message();
    	}
    
    	for (i = 0; i < count; i++) 
		{
        	words[i] = (char*)malloc(max_length * sizeof(char));
        	if (!words[i]) 
			{
            	print_error_allocating_memory_message();
        	}
    	}
    	FILE *fp;
    	fp = fopen(filename, "r");
    	int wordCount = 0;

    	if (fp == NULL) 
		{
        	print_error_message(fp);
    	}

    	while (fscanf(fp, "%s", words[wordCount]) == 1 && wordCount < count) 
		{
        	wordCount++;
    	}

    	fclose(fp);

    	return words;
}

void array_deallocation_words(char** words,int count)
{
		int i;
 		for (i = 0; i < count;i++) 
		{
        	free(words[i]);  
    	}
    	free(words); 

}

int* array_allocation_frequency_letters(char **words,int max_length)
{
		int i;
		int *letters;
		
		letters = (int *)malloc(26 * sizeof(int));
		if(!letters)
		{
			array_deallocation_words(words,max_length);
			print_error_allocating_memory_message();
		}
		
		for(i=0;i<Letters;i++)
		{
			letters[i] = 0;
		}
		return letters;

}

void array_deallocation_frequency_letters(int *letters)
{
	free(letters);
}

char * array_allocation_letters(char **words,int max_length,int *frequency_letters)
{
	int i,j;
	char *letters;
	
	letters = malloc(sizeof(char) * Letters);
	if(!letters)
	{
		array_deallocation_frequency_letters(frequency_letters);
		array_deallocation_words(words,max_length);
		print_error_allocating_memory_message();
	}
	
	for(i=0;i<Letters;i++)
	{
		letters[i] = 'A' + i;
	}
	return letters;	
}

void array_deallocation_letters(char *letters)
{
	free(letters);
}

void process_file(const char filename[])
{
	int max_length = 0 ,count= 0,lineNumber = 0;
	int *ptr,*frequency_letters;
	char** words;
	char *letters;
	
	ptr = &lineNumber;
	
	
	FILE* fp = fopen(filename, "r");
    if (fp == NULL) 
	{
        print_error_message(fp);
    }
    
    count = count_words(filename);
    max_length = find_max_length(filename);
    
    if(Check_characters(filename,max_length,&ptr))
	{
		int i;
		
		printf("LEXEIS: %d\nMEGALITERI LEXH: %d\n",count,max_length);
		words = array_allocation_words(count,max_length,filename);
    	frequency_letters = array_allocation_frequency_letters(words,max_length);
    	letters = array_allocation_letters(words,max_length,frequency_letters);
    	
    	
    	count_letter_frequency(words,frequency_letters,count,max_length);
    	print_letter_frequency(frequency_letters,letters);
		print_combinations(frequency_letters,words,max_length,letters);
		
    	array_deallocation_letters(letters);
    	array_deallocation_words(words,count);
   		array_deallocation_frequency_letters(frequency_letters);
   		 
	}
	else
	{
		print_error_file_input_message(&ptr,fp);
	}
}

int count_words(const char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
	{
        print_error_message(fp);
        exit(1);
    }

    int count = 0;
    char buffer[100];  

    while (fgets(buffer, sizeof(buffer), fp) != NULL) 
	{
        count++;
    }

    fclose(fp);
    return count;
}

int find_max_length(const char *filename)
{
	char buffer[100];  
    int max_length = 0,current_length;
	
	FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
	{
        print_error_message(fp);
        return -1;
    }

    while (fscanf(fp, "%s", buffer) == 1) 
	{
        int current_length = strlen(buffer);
        if (current_length > max_length) 
		{
            max_length = current_length;
        }
    }

    fclose(fp);
    return max_length;
}

int Check_characters(const char *arr,int max_length,int **lineNumber)
{
	FILE *fp = fopen(arr, "r");
    int i,linelength,count;
    **lineNumber = 0;

    if (fp == NULL) 
	{
        print_error_message(fp);
    }

    char *line;
    line = malloc(sizeof(char) * max_length);
    if(!line)
	{
		print_error_allocating_memory_message();
	}
    while (fscanf(fp, "%s", line) == 1) 
	{
        **lineNumber+=1;
        linelength = strlen(line);
        for (i = 0; i < linelength; i++) 
		{
            if(!(isalpha(line[i]) && isupper(line[i])))
			{
				free(line);
				fclose(fp);
				return 0;
			}	
        }
    }
    free(line);
    fclose(fp);
    return 1;
} 

int* count_letter_frequency(char **words, int letters[Letters],int count,int max_length) 
{
	int i,j;    	
    for (i = 0;i < count; i++) 
	{   
        for (j = 0; words[i][j] != '\0'; j++) 
		{    
            if (words[i][j] >= 'A' && words[i][j] <= 'Z') 
			{
                letters[words[i][j] - 'A']++;
            }
        }
    }
    return letters;
}

void print_letter_frequency(int frequency_letters[],char letters[])
{
	int i,j,max,temp;
	char temp2;
	
	for (i = 0; i < Letters - 1; i++) 
	{
        max = i;
        for (j = i + 1; j < Letters; j++) 
		{
            if (frequency_letters[j] > frequency_letters[max]) 
			{
                max = j;
            }
        }
        temp = frequency_letters[i];
        frequency_letters[i] = frequency_letters[max];
        frequency_letters[max] = temp;
        temp2 = letters[i];
        letters[i] = letters[max];
        letters[max] = temp2;
    }
	
	for(i=0;i<Letters;i++)
	{
		printf("%c:%07d\n",letters[i],frequency_letters[i]);
	}
}

void print_combinations(int *frequency_letters,char **words,int max_length,char *letters)
{
	int i,j;
	char *max_frequency;
	
	max_frequency = malloc(sizeof(char) * 5);
	if(!max_frequency)
	{
		array_deallocation_letters(letters);
		array_deallocation_frequency_letters(frequency_letters);
		array_deallocation_words(words,max_length);
		print_error_allocating_memory_message();
	}
	
	for(i=0;i<5;i++)
	{
		max_frequency[i] = letters[i];
	}
	
	printf("\n");
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			printf("%c%c\n",max_frequency[i],max_frequency[j]);
		}
	} 
	free(max_frequency);
}
