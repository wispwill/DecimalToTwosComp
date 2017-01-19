/*
Laura Josuweit
2016-11-7
signed decimal to two's complement bitstring converter

------------all functions required are contained in this file so you don't need to link a ton of stuff----------------
*/
#include<stdio.h>
#include <strings.h>

char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";//table look up table

void dec2base(char *answer, unsigned value, unsigned base);
void negate_binary(char *answer, char *src);
int main(int argc, char**argv)
{
	char answer[65];
	int input;
	
	answer[65] = '\0';
	
	printf("Enter number: ");
	scanf(" %d", &input);
	
	if(input >= 0)//positive number
	dec2base(answer, (unsigned)input, 2);//binary, base 2
	
	else//negative number
	{
		dec2base(answer, (unsigned)((-1)*(input)), 2);//input is negative, 
		//so run the negation of it through dec to base
		negate_binary(answer, answer);
	}
	
	printf("\nYou entered: %d, base(10)\n", input);

	printf("converted to Two's Complement binary: %s\n", answer);
	
	return 0;
}

void strrev(char *s, char *end)//reverses the string
{
	char holder;
	end -=1;//so we are not pointing to the null
	
	while(end > s)
	{
		//switch value of chars each pointer points to
		holder = *end;
		*end = *s;
		*s = holder;
		
		//increment pointers towards the middle
		s += 1;
		end -= 1;
		
	}
	
}
void dec2base(char *answer, unsigned value, unsigned base)
{
	unsigned quo, rem;
	char *ap;

	ap = answer;
	do
	{
		quo = value / base;//important it is integer division
		rem = value % base;
	
		*ap = digits[rem];
		ap++;
		value = quo;

	}while (value != 0);
	*ap = '0';//put a leading 0 to denote positivity
	*(ap +1)= '\0';
	

	strrev(answer, (ap+1));
	
}

void negate_binary(char *answer, char *src)
{
	char *dp, *sp;
	for(dp = answer, sp = src; *sp != '\0'; sp++, dp++)
		*dp = (*sp == '0' ? '1' : '0');
	
	*dp = '\0';//end w/ a null
	
	while(*(--dp) == '1' && dp >= answer)
		*dp = '0';//this is how you add one
	
	if(dp >= answer)
		*dp = '1';//fin with a 1	
}
