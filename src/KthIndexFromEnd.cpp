/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
char KthIndexFromEnd(char *str, int K) {
	if (str == NULL || str == "")
		return '\0';
	else{
		int len, i = 0;
		while (str[i] != '\0')
			i++;
		len = i;

		if (K<0 || K>len)
			return '\0';
		else{
			char letter;

			letter = str[(len - 1) - K];

			return letter;
		}
	}
}
