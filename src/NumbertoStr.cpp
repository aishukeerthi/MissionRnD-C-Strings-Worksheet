/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int sprint(char *str1, int num, int start, int length)
{
	//printf("Inserting number %d\n", num);
	int i;
	int temp = num;
	for (i = 0; i<length; i++)
	{
		str1[start + length - i - 1] = num % 10 + '0';
		num = num / 10;
	}
	str1[start + length ] = '\0';
	//printf("in sprintf %s\n",str1);
	return 0;
}
int powe(int x, int y)
{
	int res = 1, i;
	for (i = 1; i <= y; i++)
		res = res*x;
	return res;
}
void number_to_str(float number, char *str,int afterdecimal){
	int integer, integer_length;
	double fractional;
	int temp, i, j;
	int temp1;
	int negative_shift = 0;
	if (number < 0)
	{
		str[0] = '-';
		negative_shift = 1;
		number = -number;
	}
	integer = (int)number;

	number = number - integer;
	fractional = number * powe(10, afterdecimal);
	for (i = 0; str[i] != '\0'; i++);

	temp = integer;
	for (i = 0; temp != 0; i++)
		temp = temp / 10;
	//	printf("length is %d\n", i);
	integer_length = i;
	

	sprint(str, integer, negative_shift, integer_length);


	if (afterdecimal != 0)
	{
		str[integer_length+ negative_shift] = '.';
		sprint(str, (int)fractional, integer_length + 1+negative_shift, afterdecimal);
		//printf("%s\n",str);


	}
}
