#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int numTokens = 0;

int returnNumTokens(char* input)
{
	int count = 0; 

	if(isalpha(input[0]))
		count++;

	for(int j = 1; input[j]; j++)
	{
	
		if(input[j-1] == '-' && isalpha(input[j]))
			count++;
	
	}

	printf("---\nNumber of Tokens: %d\n", count);
	printf("---\n");
	return count;

}

char** tokenArrayReturnsAlphaArray(char **arr, int numTokens)
{
	
	printf("---\n");
	printf("0: %s\n", arr[0]);
	printf("1: %s\n", arr[1]);
	printf("2: %s\n", arr[2]);
	printf("3: %s\n", arr[3]);
	printf("4: %s\n", arr[4]);
	printf("5: %s\n", arr[5]);

	int j, k;
	char* temp;

	for(j = 0; j < numTokens; j++)
	{
		for(k = j + 1; k < numTokens; k++)
		{
			if()
			if(strcmp(arr[j], arr[k]) > 0)
			{
			
				temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
		
			}
		}
	}

	printf("---\n");
	printf("0: %s\n", arr[0]);
	printf("1: %s\n", arr[1]);
	printf("2: %s\n", arr[2]);
	printf("3: %s\n", arr[3]);
	printf("4: %s\n", arr[4]);
	printf("5: %s\n", arr[5]);

	return &arr;
}

char* insertDelimeterReturnsString(char* input)
{
	char* inputCopy = (char*) malloc(strlen(input)* sizeof(char));

	for(int i = 0; i < strlen(input); i++)
	{
		if(!isalpha(input[i]))
			strcpy(&inputCopy[i],"-");
		else
			strcpy(&inputCopy[i], &input[i]);
	}
	printf("%s\n", inputCopy);
	return inputCopy;
}

char** inputStringReturnsTokenArray(char* input, int numTokens)
{	
	
	int i = 1;
	char* token;
	const char d[2] = "-";
	char **arr = (char**)malloc(numTokens * sizeof(char));
	
	token = strtok(input, d);
	arr[0] = token;
	printf("arr[0]: %s\n", arr[0]);

	while(i < numTokens)
	{
		token = strtok(NULL, d);
		arr[i] = token;
		printf("arr[%d]: %s\n", i, arr[i]);
		i++;
	}
	
	return arr;
	
}

int main(int argc, char** argv)
{

	if(argc > 2)
	{
		fprintf(stderr, "Too many arguments.\n");
		exit(E2BIG);
	}

	char* delimterInput = insertDelimeterReturnsString(argv[1]);

	numTokens = returnNumTokens(delimterInput);

	char** tokenArray = inputStringReturnsTokenArray(delimterInput, numTokens);

	char** alphabetizedArray = tokenArrayReturnsAlphaArray(tokenArray, numTokens);

	free(delimterInput);
	free(tokenArray);

	return 1;
}