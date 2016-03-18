/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
//typedef int bool;



#define true 1
#define false 0

int find_words(char *str, char **list)
{

	int i = 0, j = 0, count = 0, length = 0;


	while (str[i] != '\0')
		i++;
	length = i;


	for (i = 0; i <= length; i++)
	{

		if (str[i] != ' ')
		{
			list[count][j] = str[i];
			j++;
		}
		else
		{
			list[count][j] = '\0';  count++; j = 0;
		}
	}
	return count + 1;
}


bool compare_words(char *str1, char *str2)
{
	bool result = false;
	int i = 0;

	//First comparing the lengths
	int length1 = 0, length2 = 0;
	while (str1[i] != '\0')
		i++;
	length1 = i;
	i = 0;
	while (str2[i] != '\0')
		i++;
	length2 = i;
	if (length1 != length2)
		return false;
	for (i = 0; i<length1; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	else{
		char **words1, **words2, **common_words;
		common_words = (char**)malloc(SIZE*sizeof(char*));
		words1 = (char **)malloc(SIZE*sizeof(char *));
		words2 = (char **)malloc(sizeof(char *)*SIZE);
		int i, j;
		for (i = 0; i < SIZE; i++)
		{
			words1[i] = (char*)malloc(SIZE*sizeof(char));
			words2[i] = (char*)malloc(SIZE*sizeof(char));
			common_words[i] = (char *)malloc(SIZE*sizeof(char));

		}

		int num_words1, num_words2;

		num_words1 = find_words(str1, words1);
		num_words2 = find_words(str2, words2);
		int k = 0;
		for (i = 0; i < num_words1; i++)
		{
			for (j = 0; j < num_words2; j++)
			{
				if (words1[i][0] != '\0' &&  compare_words(words1[i], words2[j]))
				{
					common_words[k] = words1[i];
					k++;
				}
			}
		}
		if (k == 0)
		{
			return NULL;
		}
		return common_words;
	}

}